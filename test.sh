# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 22:57:59 by hhow-cho          #+#    #+#              #
#    Updated: 2019/06/11 02:28:14 by hhow-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

TMP_DIR=~/tmp_ft_ls
TMP_DIR_LOG=~/tmp_ft_ls_log
LOG=${TMP_DIR_LOG}/log
RESULT=${TMP_DIR_LOG}/result
LOG_2=${TMP_DIR_LOG}/log_2
RESULT_2=${TMP_DIR_LOG}/result_2

export LANG="en_US.UTF-8"

while [ ! -z "${1}" ]; do
	if [[ "${1}" =~ ^-- ]]
	then
		printf "\033[31m${1}: Invalid option\n\033[0m"
		exit
	else
		FT_LS_PATH="${1}"
	fi
	shift 1
done
if [ -z "${FT_LS_PATH}" ]; then FT_LS_PATH="./ft_ls"; fi

clear

if [ ! -e "${FT_LS_PATH}" ]; then
	printf "\033[31m${FT_LS_PATH}: No such file\n\033[0m"
	exit
fi


quit()
{
	# rm -rf "${TMP_DIR}" empty
	exit 1
}

execute()
{
	/bin/ls -1 ${1} > ${RESULT} 2> ${RESULT_2}
	OUR_RET=($?)
	"${FT_LS_PATH}" -1 ${1} > ${LOG} 2> ${LOG_2}
	YOUR_RET=($?)
	if [ $OUR_RET -ne $YOUR_RET ]; then
		printf "\r\n\033[31mError:\t\t\033[0m\033[37;1m ls ${1}\033[0m\n\n"
		printf "/bin/ls return: %d | ft_ls return: %d\n\n" $OUR_RET $YOUR_RET
		quit
	elif [ $OUR_RET -ne 0 ] && !(diff  ${LOG_2} ${RESULT_2}); then
		printf "\r\n\033[31mError:\t\t\033[0m\033[37;1m ls ${1}\033[0m\n\n"
		diff  ${RESULT_2} ${LOG_2}
		quit
	elif !(diff  ${LOG} ${RESULT}) then
		printf "\r\n\033[31mError:\t\t\033[0m\033[37;1m ls ${1}\033[0m\n\n"
		diff  ${LOG} ${RESULT}
		quit
	else
		printf "\n\033[32mSuccess:\t\033[37;1m ls ${1}\033[0m\n\n"
	fi
}

rm -rf "${TMP_DIR}" empty
mkdir "${TMP_DIR}"
mkdir "${TMP_DIR_LOG}"
# mkdir -p includes_empty

mkdir -p ${TMP_DIR}/temp_dir
touch ${TMP_DIR}/temp_dir/file1
touch ${TMP_DIR}/temp_dir/zzzzz
touch ${TMP_DIR}/temp_dir/file2
touch ${TMP_DIR}/temp_dir/+file
touch ${TMP_DIR}/temp_dir/zfile
touch -at 9999081011 ${TMP_DIR}/temp_dir/file1
touch ${TMP_DIR}/temp_dir/file2
touch -at 9999115045 ${TMP_DIR}/temp_dir/file3
touch -at 17091104 ${TMP_DIR}/temp_dir/file4
touch ${TMP_DIR}/temp_dir/file5
touch -at 12115659 ${TMP_DIR}/temp_dir/file6
touch -at 17012020 ${TMP_DIR}/temp_dir/file7
touch -at 9412290106 ${TMP_DIR}/temp_dir/file8
touch -at 1612250101 ${TMP_DIR}/temp_dir/file9
ln -s ${TMP_DIR}/temp_dir/zzzzz ${TMP_DIR}/temp_dir/link
ln -s ${TMP_DIR}/temp_dir/link_the_loopy_hero ${TMP_DIR}/temp_dir/link_the_loopy_hero
mkdir -p ${TMP_DIR}/temp_dir/dir1
mkdir -p ${TMP_DIR}/temp_dir/dir2
mkdir -p ${TMP_DIR}/temp_dir/dir1/dir3
touch ${TMP_DIR}/temp_dir/dir1/dir3/go_go_gadget_robotest
touch ${TMP_DIR}/temp_dir/dir1/hi_mom
mkdir -p ${TMP_DIR}/temp_dir/dir1/dir_dir_dir_dir_dir

printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITHOUT ARGUMENT ~               +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "-l"
execute "-l1"
execute "-1l"
execute "-d"
execute "-S"
execute "-lg"
execute "-g"
execute "-a"
execute "-r"
execute "-R"
execute "-t"
execute "-u"
execute "-f"
execute "-i"
execute "-Rt"
execute "-RtU"
execute "-al"
execute "-alr"
execute "-alrt"
execute "-alrut"
execute "-alutf"
execute "-aR"
execute "-aRu"
execute "-aRuf"
execute "-alrutf"
execute "-alrutfd"
execute "-alrutfdS"
execute "-alrutfdi"

printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH NUL ARGUMENT FOLDER ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "-l includes includes"
execute "-a includes includes"
execute "-r includes includes"
execute "-R includes includes"
execute "-t includes includes"
execute "-u includes includes"
execute "-t includes/ includes/"
execute "-tu includes/ includes/"
execute "-f includes/ includes/"
execute "-fr includes/ includes/"
execute "-frRS includes/ includes/"



printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH ONE ARGUMENT FOLDER ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "-l includes"
execute "-a includes"
execute "-r includes"
execute "-R includes"
execute "-t includes"
execute "-u includes"
execute "-f includes"
execute "-fud includes"

printf "\033[44m\033[1;37m"


printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH ONE ARGUMENT FILE ~         +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "Makefile"
execute "-l Makefile"
execute "-a Makefile"
execute "-r Makefile"
execute "-R Makefile"
execute "-t Makefile"
execute "-Rt Makefile"
execute "-al Makefile"
execute "-alr Makefile"
execute "-u Makefile"
execute "-alrt Makefile"
execute "-alrtRu Makefile"
execute "-alrtRuf Makefile"
execute "-alrtRuf -S Makefile"



printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#      ~ TESTS WITH TWO OR MORE ARGUMENT ~          +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"


execute "-l -a includes"
execute "-l -a -r includes"
execute "-l -a -r -R includes"
execute "-l -a -r -R -t includes"
execute "-l -a -r -R -t -u includes"
execute "-l -a -r -R -t -uS includes"
execute "-l -a -r -R -t -u -f includes"
execute "-l -a -r -R -t -u -f -d includes"
execute "-l -a -r -R -t -u -f -d -S includes"


printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#        ~ TEST WITH JOINED ARGUMENTS ~             +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "-la includes"
execute "-rla includes"
execute "-rlRa includes"
execute "-trlRa includes"
execute "-l -a includes"
execute "-u includes"
execute "-l -ua includes"
execute "-l -gua includes"
execute "-l -guad includes"

printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS THAT FAILS IN /bin/ls -1 ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "-1"
execute "-1 Makefile99 Makefile98 Makefile1"
execute "-1 123154 . Makefile177777"
execute "-1 .546351451635 .546351451636"
execute "-1 -lu .546351451635 .546351451636"
execute "-1 -lug .546351451635 .546351451636"
execute "-1 -lug -d .546351451635 .546351451636"
execute "-1 -fu .546351451635 .546351451636"
execute "-1 -fu -S .546351451635 .546351451636"

printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH HARD DATA SET       ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "${TMP_DIR}"
execute "-l ${TMP_DIR}"
execute "-a ${TMP_DIR}"
execute "-r ${TMP_DIR}"
execute "-R ${TMP_DIR}"
execute "-t ${TMP_DIR}"
execute "-Rt ${TMP_DIR}"
execute "-al ${TMP_DIR}"
execute "-alr ${TMP_DIR}"
execute "-u ${TMP_DIR}"
execute "-alrt ${TMP_DIR}"
execute "-alrtRu ${TMP_DIR}"
execute "-alrtRuf ${TMP_DIR}"
execute "-alrtRuf -S ${TMP_DIR}"




printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH BIG DATA SET        ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

execute "-R ~"
execute "-RS ~"
execute "-R ~/"
execute "-Rul ~/"
execute "-RulS ~/"
execute "-Rulf ~/"
execute "-Rulrf ~/"
execute "-Rulrfl ~/"
execute "-Rulrflg ~/"
execute "-Rulrflgd ~/"
execute "-RulrSlgd ~/"
execute "-Rulr -Slg -d ~/"
execute "-Rulr -Slg ~/"
execute "-Rulr -Slg -i ~/"




printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH BIG DATA SET        ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"



execute "-R ~"
execute "-RS ~"
execute "-R ~/"
execute "-RU ~/"
execute "-RUl ~/"
execute "-RUlt ~/"
execute "-Rul ~/"
execute "-RulS ~/"
execute "-Rulf ~/"
execute "-Rulrf ~/"
execute "-Rulrfl ~/"
execute "-Rulrflg ~/"
execute "-Rulrflgd ~/"
execute "-RulrSlgd ~/"
execute "-RulrSlgdn ~/"
execute "-Rulr -Slg -d ~/"
execute "-Rulr -Slg ~/"
execute "-Rulr -Slg -i ~/"


printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH / CASE              ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

mkdir empty 

execute "- "
execute "-S "
execute "- /"
execute "-ul /"
execute "-ulS /"
execute "-ulf /"
execute "-ulf /"
execute "-ulfl /"
execute "-ulflg /"
execute "-ulflgn /"
execute "-ulflgd /"
execute "-ulSlgd /"
execute "-ul -Slg -d /"
execute "-ul -Slg /"
execute "-ul -Slg -i /"

printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH /etc CASE              ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

mkdir empty 

execute "-R /etc"
execute "-RS /etc"
execute "-R /etc"
execute "-Rul /etc"
execute "-RulS /etc"
execute "-Rulf /etc"
execute "-Rulrf /etc"
execute "-Rulrfl /etc"
execute "-Rulrflg /etc"
execute "-Rulrflgd /etc"
execute "-RulrSlgd /etc"
execute "-Rulr -Slg -d /etc"
execute "-Rulr -Slg /etc"
execute "-Rulr -Slg -i /etc"
execute "-R /etc/"
execute "-RS /etc/"
execute "-R /etc/"
execute "-Rul /etc/"
execute "-Ruln /etc/"
execute "-RulS /etc/"
execute "-Rulf /etc/"
execute "-Rulrf /etc/"
execute "-Rulrfl /etc/"
execute "-Rulrflg /etc/"
execute "-Rulrflgd /etc/"
execute "-RulrSlgd /etc/"
execute "-Rulr -Slg -d /etc/"
execute "-Rulr -Slg /etc/"
execute "-Rulr -Slg -i /etc/"


printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH SPECIFIC CASE       ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

mkdir empty 

execute "-l empty"
execute "-l empty empty"
execute "-l /usr/local/bin/node"
execute "--"
execute "-- -- ."
execute "-- -- includes"
execute "-- - includes"

printf "\033[44m\033[1;37m"

printf "# **************************************************************************** #\n"
printf "#                                                                              #\n"
printf "#                                                         :::      ::::::::    #\n"
printf "#                                                       :+:      :+:    :+:    #\n"
printf "#                                                     +:+ +:+         +:+      #\n"
printf "#          ~ TESTS WITH ERRORS CASE       ~       +#+  +:+       +#+         #\n"
printf "#                                                 +#+#+#+#+#+   +#+            #\n"
printf "#                                                      #+#    #+#              #\n"
printf "#                                                     ###   ########.fr        #\n"
printf "#                                                                              #\n"
printf "# **************************************************************************** #\n\n\n"

printf "\033[0m"

mkdir empty 

execute "9 8 7 5 4 4 4 5 662123 4 6 2"
execute "9 8 7 5 4 4 4 5 662123 4 6 2 Makefile ft_ls"
execute " Makefile ft_ls 9 8 7 5 4 4 4 5 662123 4 6 2"
execute "  ''  "

# printf "\033[44m\033[1;37m"

# printf "# **************************************************************************** #\n"
# printf "#                                                                              #\n"
# printf "#                                                         :::      ::::::::    #\n"
# printf "#                                                       :+:      :+:    :+:    #\n"
# printf "#                                                     +:+ +:+         +:+      #\n"
# printf "#          ~ TESTS WITH /dev                ~       +#+  +:+       +#+         #\n"
# printf "#                                                 +#+#+#+#+#+   +#+            #\n"
# printf "#                                                      #+#    #+#              #\n"
# printf "#                                                     ###   ########.fr        #\n"
# printf "#                                                                              #\n"
# printf "# **************************************************************************** #\n\n\n"

# printf "\033[0m"

# execute "-l /dev"

exit 0