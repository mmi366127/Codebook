#!/bin/bash
echo "$GITHUB_TOKEN" | docker login -u "$DOCKER_USERNAME" --password-stdin docker.pkg.github.com
docker push docker.pkg.github.com/brianbbsu/bbqube/auto-build:latest
