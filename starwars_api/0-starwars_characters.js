#!/usr/bin/node
const request = require('request');

const movie_id = process.argv[2];
const starwars_api = `https://swapi.dev/api/films/${movie_id}/`;

request(starwars_api, async (error, response, body) => {
  if (error) {
    console.error(error);
  } else {
    const res_char = JSON.parse(body).characters;
    for (const url of res_char) {
      await new Promise((resolve, reject) => {
        request(url, (error, response, body) => {
          if (error) {
            console.error(error);
          } else {
            const char = JSON.parse(body);
            console.log(char.name);
          }
          resolve();
        });
      });
    }
  }
});
