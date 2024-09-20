all: 
	@mkdir -p /home/$(USER)/data/wordpress
	@mkdir -p /home/$(USER)/data/mariadb
	@docker-compose -f srcs/docker-compose.yml up -d --build

down:
	@docker-compose -f srcs/docker-compose.yml down --volumes --remove-orphans

rm:
	@docker-compose -f srcs/docker-compose.yml rm

re: 
	all down

.PHONY: all down
