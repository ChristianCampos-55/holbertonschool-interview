#!/usr/bin/node
/*
    A script that prints all characters of a Star Wars movie
*/

const u = require('util');
const request = u.promisify(require('request'));
const as = process.argv.slice(2);

async function characterPrinter (film) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + film;
  let d = await (await request(url)).body;
  d = JSON.parse(d);
  const chars = d.characters;
  for (let index = 0; index < chars.length; index++) {
    const urlCharacter = chars[index];
    let char = await (await request(urlCharacter)).body;
    char = JSON.parse(character);
    console.log(character.name);
  }
}

characterPrinter(as[0]);
