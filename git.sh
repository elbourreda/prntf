#!/bin/bash

echo -n "Would you like to (a)dd or to (r)emove files? "
read	ch1
case	$ch1 in
		a|add)
					ch1='add'
							;;
								r|remove)
											ch1='rm'
													;;
														*)
																	echo "'$ch1' is an invalid command!"
																			exit 1
																					;;
																			esac
																			echo -n "Which files would you like to $ch1 : "
																			read -e ch2
																			echo -n "Insert your commit : "
																			read	ch3
																			git $ch1 $ch2 && git commit -m "$ch3" && git push

