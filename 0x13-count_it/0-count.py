#!/usr/bin/python3

"""
recursive function that queries the Reddit API,
parses the header of all hot articles,
and prints a sorted count of given keywords
"""

import requests
import pprint
import re


def count_words(subreddit, word_list, hot=[], after=None):
    """
    function that uses the Reddit API
    """
    meta = {'User-agent': 'Unix:0-subs:v1'}
    queu = {'limit': 100}

    if isinstance(after, str):
        if after != "STOP":
            queu['after'] = after
        else:
            return res_printer(word_list, hot)

    ans = requests.get('http://reddit.com/r/{}/hot.json'.format(
                                subreddit),headers=meta, params=queu)
    if ans.status_code is not 200:
        return None
    data = ans.json().get('data', {})
    after = data.get('after', 'STOP')
    if not after:
        after = "STOP"
    hot = hot + [post.get('data', {})
                 .get('title') for post in data.get('children', [])]
    return count_words(subreddit, word_list, hot, after)


def res_printer(word_list, hot):
    """
    prints whats fetched
    """
    a = {}
    for it in word_list:
        a[it] = 0
    for header in hot:
        for it in word_list:
            for tw in header.lower().split():
                if tw == it.lower():
                    a[it] += 1

    a = {k: v for k, v in a.items() if v > 0}

    its = list(a.keys())

    for it in sorted(its, reverse=True,
                       key=lambda k: a[k]):
        print("{}: {}".format(it, a[it]))
