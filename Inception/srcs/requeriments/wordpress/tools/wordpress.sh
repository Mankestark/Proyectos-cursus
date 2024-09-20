#!/bin/bash

rm -f /var/www/html/wp-config.php

rm -rf /var/www/html/*

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
mv wp-cli.phar /usr/local/bin/wp

chmod 777 /var/www/html
chmod 777 /var/www/

cd /var/www/html

su www-data -s /bin/bash -c "
    cd /var/www/html &&
    wp core download &&
    wp core config --dbname=$DB_SQL --dbuser=$DB_USER --dbpass=$DB_PASSWORD --dbhost=$WP_DB_HOST &&
    wp core install --url=$DOMAIN_NAME --title=$DOMAIN_NAME --admin_user=$WP_ADMIN --admin_password=$WP_ADMIN_PASSWORD --admin_email=$WP_ADMIN_EMAIL --allow-root &&
    wp user create $WP_USER $WP_EMAIL --role=author --user_pass=$WP_PASSWORD --allow-root
"

exec php-fpm7.3 -F
