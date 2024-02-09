#!/usr/bin/node
const request = require('request');

const movieId = process.argv[2];
const starApi = `https://swapi.dev/api/films/${movieId}/`;

request(starApi, async (error, response, body) => {
  if (error) {
    console.error(error);
  } else {
    const resChar = JSON.parse(body).characters;
    for (const url of resChar) {
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
