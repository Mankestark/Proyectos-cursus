FROM debian:buster

RUN apt-get update && \
    apt install nginx -y openssl vim curl

COPY ./conf/default /etc/nginx/nginx.conf
RUN chmod 777 /etc/nginx/nginx.conf

COPY ./tools/nginx.sh /tools/nginx.sh


RUN chmod +x /tools/nginx.sh


CMD ["/tools/nginx.sh"]
