# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    check_prototypes.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 19:07:43 by kbatz             #+#    #+#              #
#    Updated: 2018/11/23 19:43:19 by kbatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ls -l | rev | cut -d ' ' -f 1 | rev | grep ".c$" | sed "s/.c$//" | sort > srcs
cat libft.h | grep "ft_" | rev | cut -d '	' -f 1 | rev | cut -d '(' -f 1 | tr -d '\*' | sed "s/^ft_//" | sort > prttps
diff srcs prttps | grep " " | cat -d " " -f 2 > prttps
