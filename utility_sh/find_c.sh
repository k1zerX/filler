# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_c.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbatz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:09:35 by kbatz             #+#    #+#              #
#    Updated: 2019/09/13 22:09:42 by kbatz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ls -l $1 | rev | cut -d ' ' -f 1 | rev | grep ".c$" | rev | sed "s/ //" | rev