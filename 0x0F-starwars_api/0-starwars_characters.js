#!/usr/bin/node
/*
    A script that prints all characters of a Star Wars movie
*/

const u = require('util');
const request = u.promisify(require('request'));
const as = process.argv.slice(2);

async function starwarsCharacters (film) {
  const url = 'https://swapi-api.hbtn.io/api/films/' + film;
  let d = await (await request(url)).body;
  d = JSON.parse(d);
  const characters = d.characters;
  for (let index = 0; index < characters.length; index++) {
    const urlCharacter = characters[index];
    let character = await (await request(urlCharacter)).body;
    character = JSON.parse(character);
    console.log(character.name);
  }
}

starwarsCharacters(as[0]);
