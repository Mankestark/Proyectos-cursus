FROM debian:buster

RUN apt-get update && apt upgrade -y && \
    apt install -y wget vim curl procps \
    php7.3 \
    php7.3-fpm \
    php7.3-mysql \
    mariadb-client 

RUN mkdir -p /run/php
RUN chmod +w /run/php

COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/.

COPY ./tools/wordpress.sh ./tools/

RUN chmod +x /tools/wordpress.sh

CMD ["./tools/wordpress.sh"]
