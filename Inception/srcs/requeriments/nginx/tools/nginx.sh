#!/bin/bash

mkdir -p /etc/ssl/certs/
cd /etc/ssl/certs/

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout nginx-selfsigned.key -out nginx-selfsigned.crt -subj "/C=ES/ST=Andalucia/L=Malaga/O=42/OU=42Malaga/CN=$DOMAIN_NAME"

chmod 600 nginx-selfsigned.key

chmod 600 nginx-selfsigned.crt

chmod 777 /var/www/html
chmod 644 /var/www/html/*

chown -R www-data:www-data /var/www/html

exec nginx -g "daemon off;"

