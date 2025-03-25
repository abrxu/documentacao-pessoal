## Some important commands:

- Get into Docker Container bash:
-> docker exec -ti CONTAINER_NAME /bin/bash
(to exit just Ctrl + D or type exit)

- Create PSQL dump inside the Docker Container:
-> docker exec -t CONTAINER_NAME pg_dump -U postgres -F c -b -v -f /tmp/EXAMPLE_FILE.bkp DB_NAME

- Restore PSQL dump inside the Docker Container
-> docker exec -it CONTAINER_NAME pg_restore -U postgres -d DB_NAME -v /EXAMPLE_FILE.bkp

- Copy the PSQL dump inside the Docker Container to Local Machine:
-> docker cp DOCKER_NAME:/tmp/EXAMPLE_FILE.sql ./EXAMPLE_FILE.sql

- Copy some file in the Local Machine and put inside a Docker Container
-> docker cp .\EXAMPLE_FILE.bkp CONTAINER_NAME:/tmp/EXAMPLE_FILE.bkp
