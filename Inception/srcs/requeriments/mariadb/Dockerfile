FROM debian:buster

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y vim mariadb-server procps

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/
COPY ./tools/mariadb.sh /tools/

RUN chmod +x /tools/mariadb.sh

CMD ["/tools/mariadb.sh"]