# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    make_prototypes.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 19:43:32 by kbatz             #+#    #+#              #
#    Updated: 2018/11/23 21:00:38 by kbatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

rm -Rf allprttps
touch allprttps
for var in atoi.c bzero.c isalnum.c isalpha.c isascii.c isdigit.c isprint.c itoa.c memalloc.c memccpy.c memchr.c memcmp.c memcpy.c memdel.c memmove.c memset.c putchar.c putchar_fd.c putendl.c putendl_fd.c putnbr.c putnbr_fd.c putstr.c putstr_fd.c strcat.c strchr.c strclr.c strcmp.c strcpy.c strdel.c strdup.c strequ.c striter.c striteri.c strjoin.c strlcat.c strlen.c strmap.c strmapi.c strncat.c strncmp.c strncpy.c strnequ.c strnew.c strnstr.c strrchr.c strsplit.c strstr.c strsub.c strtrim.c tolower.c toupper.c
do
	cat $var | head -n 15 | tail -n 1 | sort | sed "s/$/;/" | sed "s/    /	/p" >> allprttps
	#echo ft_$var | sed "s/\.c//"
	#cat $var | grep "	ft_" | grep -v ";" | sort | sed "s/$/;/" | sed "s/    /  /p" >> allprttps
done
