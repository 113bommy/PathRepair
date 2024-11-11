"""


██╗ ██████╗ ██╗    ██████╗  ██████╗  ██╗ █████╗
██║██╔═══██╗██║    ╚════██╗██╔═████╗███║██╔══██╗
██║██║   ██║██║     █████╔╝██║██╔██║╚██║╚██████║
██║██║   ██║██║    ██╔═══╝ ████╔╝██║ ██║ ╚═══██║
██║╚██████╔╝██║    ███████╗╚██████╔╝ ██║ █████╔╝
╚═╝ ╚═════╝ ╚═╝    ╚══════╝ ╚═════╝  ╚═╝ ╚════╝
 __  __ _                   
|  \/  (_)_ __ ___  _ __    
| |\/| | | '__/ _ \| '_ \  
| |  | | | | | (_) | | | | 
|_|  |_|_|_|  \___/|_| |_|  
"""
"""
    Красивое лучше, чем уродливое.
    Явное лучше, чем неявное.
    Простое лучше, чем сложное.
    Сложное лучше, чем запутанное.
    Плоское лучше, чем вложенное.
    Разреженное лучше, чем плотное.
    Читаемость имеет значение.
    Особые случаи не настолько особые, чтобы нарушать правила.
    При этом практичность важнее безупречности.
    Ошибки никогда не должны замалчиваться.
    Если они не замалчиваются явно.
    Встретив двусмысленность, отбрось искушение угадать.
    Должен существовать один и, желательно, только один очевидный способ сделать это.
    Хотя он поначалу может быть и не очевиден, если вы не голландец [^1].
    Сейчас лучше, чем никогда.
    Хотя никогда зачастую лучше, чем прямо сейчас.
    Если реализацию сложно объяснить — идея плоха.
    Если реализацию легко объяснить — идея, возможно, хороша.
    Пространства имён — отличная штука! Будем делать их больше!
"""
"""
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░▓████████████████████████▒░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░▓█████▓▒░░░░░░░░░░░░░░░▒██████▒░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░████▒░░░░░░░░░░░░░░░░░░░░░░░░░▓███▒░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███░░░░░░░░░░░░░░░
░░░░░░░░░░░░░▒██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒██░░░░░░░░░░░░░░
░░░░░░░░░░░░▒██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░░
░░░░░░░░░░░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░░░░░░░░░
░░░░░░░░░░░██▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒░░██░░░░░░░░░░░░
░░░░░░░░░░░██░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░██░░░░░░░░░░░
░░░░░░░░░░░██░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░██░░░░░░░░░░░
░░░░░░░░░░░██░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░██░░░░░░░░░░░
░░░░░░░░░░░██▒░██▓░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██▓░▒██░░░░░░░░░░░
░░░░░░░░░░░░██░░██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░██░░░░░░░░░░░░
░░░░░░░░░░░░██▒░██░░░░░▒▒▓███▒░░░░░░░▒███▓▒▒░░░░░██░▓██░░░░░░░░░░░░
░░░░░░░░░░░░░██░██░░██████████▒░░░░░▓██████████░░██▒██░░░░░░░░░░░░░
░░░░░░░░░░░░░░████░████████████░░░░░████████████░████░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░███░▒██████████░░░░░░░██████████▒░██▒░░░░░░░░░▒░░░░░
░░░▒████░░░░░░░▓█▒░░█████████░░░░░░░░░█████████░░▒█▓░░░░░░▓████░░░░
░░░██░▒██▒░░░░░██░░░░██████▓░░░░█░█░░░░███████░░░░██░░░░░███░░██░░░
░░░██░░░██▓░░░░██░░░░░░▒▓▓░░░░▒██░██░░░░░▓▓▒░░░░░▒██░░░░███░░░██░░░
░▓██▒░░░░████▓░░██░░░░░░░░░░░░███░███░░░░░░░░░░░░██░░█████░░░░▓██▒░
██▓░░░░░░░░▒████████▓░░░░░░░░████░███▓░░░░░░░▒▓████████░░░░░░░░░███
██▓▒▓███▓░░░░░░▓████████▓░░░░████░███▓░░░░▓████████▓░░░░░░████▓▓███
░███████████▒░░░░░░███████░░░░██░░░██░░░░██████▓░░░░░░▓███████████░
░░░░░░░░░░▓█████░░░░██▓▓░██░░░░░░░░░░░░░██░█▒██░░░▒█████▓░░░░░░░░░░
░░░░░░░░░░░░░▒█████▒▒█▓█░███▓▓▒▒▒▓▒▒▓▓▓███▒███░▓█████░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░▒████▒▓█▒▒█░█▒█░█░█▓█▒█▓░█░█████▒░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░██░░██▓█▓█▓█▒█▒█▓█▓████░▓█▓░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░▓████▓░▓█▓█░█▒█░█░█▒█▒███▒░██████░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░▓█████░░██░░░▒█████▓█▓█████▒░░░██░▒█████▓░░░░░░░░░░░░░
░░░░▒██████████▓░░░░░███░░░░░░░░░░░░░░░░░░░██▒░░░░░▓██████████▒░░░░
░░░░██░░░▓▓▓░░░░░░▒██████▓░░░░░░░░░░░░░░░███████▒░░░░░░▓▓▒░░▒██░░░░
░░░░▓██░░░░░░░░▓████▓░░░█████▒░░░░░░▒▓█████░░░▓████▓░░░░░░░▒██▓░░░░
░░░░░░███░░░░████▒░░░░░░░░▓█████████████▒░░░░░░░░▒████░░░░███░░░░░░
░░░░░░░██░░░██▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▓██░░░██░░░░░░░
░░░░░░░██▒▓██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒██▒▓██░░░░░░░
░░░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
"""
"""

░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░▌░░░▀
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░▌░░░▀
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░█▌░░░▀
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▀█████████████████████████████████████████████████▀▀
░░░░░░░░░░░░░░░░░░░░░░░░░░▄▄▄████▄████████ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ██ ████▀▀
░░░░░░░░░░░░░░░░░░░░░░░░░░░▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█████████▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████░░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████░░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████░░░░░░░░░░░░░░░
"""
"""


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@#@@#@@ @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##@M@M # #@@@M@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@#@@ @@@@@@M@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@### #@@B@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@B@@#@@@@@#M@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@##@@M@#@@##@##@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@#M@@@@@##@M@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@##@@@@@@#@##@#@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@#  @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@M@@  #
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@#@@#@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @# @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @# @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@#@@#@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@M@@  #
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@#  @
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ @@#@@#@@@@@@@@@@@@@@@@@#@@#@#@@@@@@@@@@@@@@@@@@@@@#@#@@@@@@@@@@@@@@@@@@@@@@@@@
 @ #@@@@@@@@@@@@@@@@@@@@#@@@@@@#@@@@@@@@@@@@@@@@@#@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@ @@#@#@@@@@@@@@@@@@@@@@@#@####@@@@@@@@@@@@@@@@@M@#@@#@#@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@#@#M@@@M@@@@@@@@@@@@@@@@@@@M@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#@M@#@#@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@M@@M@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@#@@#@@@@@@@@@@@@@@@@@@@@M@M@#@@@@@@@@@@@@@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@
@@#@@#@@@@@@@@@@@@@@@@@@@@@@@M@                   @M@@#@@@@@@@@@@@@@@@@@@@@@@@@@
@#@@@@@#@@@@@@@@@@@@@@@@@@@#@@                     @@@@M@@@@@@@@@@@@@@@@@@@@@@@@
@@@#@@@##@@@#@@@@@#@@@@@##@@@@                     #@#@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@####@@####@@@@#@@@@M@@@#@@#                     @@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@#@          @#@@#@@@       #@             @       #@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                            @#           @@#@@     #@@#@@@@@@@@@@@@@@@@@@@@@@@@@
                     ##@#@@ #M           @# @@     @@M  @@@@@@@@@@@@@@@@@@@@@@@@
                     @#@@@M #@           #@   #    @@   @@@@@@@@@@@@@@@@@@@@@@@@
                      @@ @@#@@           ##    @##@@    @@@@@@@@@@@@@@@@@@@@@@@@
                      @#  @@M@           @@             @@@@@@@@@@@@@@@@@@@@@@@@
    @@@##@@@          @@@@ @@@          @@               #@#@@#@@@@@@@@@@@@@@@@@
@@@@###@@###@@@@#@#@@@@#@@@ M@          #@    @       B  @@@#@@@@@@@@@@@@@@@@@@@
@M@@@@@MM@@@@@M@@#@##@@@#@@M@B          @#   M@   @# #@  #@@#@@@@@@@@@@@@@@@@@@@
@#@#@@M@@M@@#@#@#@#@@#@#@#@@@@          @#   @@   #  @M  @#@@@@@@@@@@@@@@@@@@@@@
@@@          @@@@#@##@     #@#          @M    #  @   @   @@@@@#@@@@@@@@@@@@@@@@@
                            @@          @@   @#@@#@@#M   #@@@@#@@@@@@@@@@@@@@@@@
                           M@#           #@   @@@@##@@ @M@#M@@@#@@@@@@@@@@@@@@@@
                           @@@@           @@          @@@#@@@#@#@@@@@@@@@@@@@@@@
                          @#  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                          @@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
   @M@H@@  @#        @#@@@@#@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@#@#@##@M@@@M@ @M#@@@@@#@@#@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#M@@@##@@@@@@@@M@@@@#@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@#@@@@@M@#@M@@B#M@@M@###@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
###@@@@@@@@@# @#@@@@@@@#@@@#@##@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@#@@M@@@#@@#@#@@@@@@#@@@#@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@M@#@# 
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@M@@@@#
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@#@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@M@@##
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@#@M
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@###@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#@@@@@#@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#  #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#  #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


"""
"""
                          / \  //\
            |\___/|      /   \//  \\
            /0  0  \__  /    //  | \ \    
           /     /  \/_/    //   |  \  \  
           @_^_@'/   \/_   //    |   \   \ 
           //_^_/     \/_ //     |    \    \
        ( //) |        \///      |     \     \
      ( / /) _|_ /   )  //       |      \     _\
    ( // /) '/,_ _ _/  ( ; -.    |    _ _\.-~        .-~~~^-.
  (( / / )) ,-{        _      `-.|.-~-.           .~         `.
 (( // / ))  '/\      /                 ~-. _ .-~      .-~^-.  \
 (( /// ))      `.   {            }                   /      \  \
  (( / ))     .----~-.\        \-'                 .~         \  `. \^-.
             ///.----..>        \             _ -~             `.  ^-`  ^-_
               ///-._ _ _ _ _ _ _}^ - - - - ~                     ~-- ,.-~
                                                                  /.-~

"""
"""
  ____          _      _____                       
 / ___|___   __| | ___|  ___|__  _ __ ___ ___  ___ 
| |   / _ \ / _` |/ _ \ |_ / _ \| '__/ __/ _ \/ __|
| |__| (_) | (_| |  __/  _| (_) | | | (_|  __/\__ \
 \____\___/ \__,_|\___|_|  \___/|_|  \___\___||___/
"""
"""
░░██▄░░░░░░░░░░░▄██
░▄▀░█▄░░░░░░░░▄█░░█░
░█░▄░█▄░░░░░░▄█░▄░█░
░█░██████████████▄█░
░█████▀▀████▀▀█████░
▄█▀█▀░░░████░░░▀▀███
██░░▀████▀▀████▀░░██
██░░░░█▀░░░░▀█░░░░██
███▄░░░░░░░░░░░░▄███
░▀███▄░░████░░▄███▀░
░░░▀██▄░▀██▀░▄██▀░░░
░░░░░░▀██████▀░░░░░░
░░░░░░░░░░░░░░░░░░░░
"""
"""
n = int(input())
os=0
ch=[]
for i in range(n):
	m = int(input())
	ch.append(m)	
	if ch[0]==10:		
		if 1 in ch:
			print((len( ch[:ch.index(1)])))
			break
	else:
		if 10 in ch:
			print((len( ch[:ch.index(10)])))
			break
"""
"""
n,m = map(int,input().split())
m = float(m)
mi = []
for i in range(n):
	a,b = map(float,input().split())
	mi.append((a*m)/b)
print(round(min(mi),6))
"""
"""
l = input().split()
l = set(l)
print(len(l))

"""
"""	
x = input()
y = x[1:-1]
z = set(y.split(', '))
if x == "{}":
	print(0)
else:
	print(len(z))
"""
"""
n,k = map(int,input().split())
L = sorted(map(int, input().split()))
res = [L[0]]
for i in range(1,n):
    if L[i] != L[i-1]:
        res.append(L[i]-L[i-1])
l = len(res)
if k > l:
    res += [0]*(k-l)
for i in range(k):
    print(res[i])

"""	
"""
from math import*
s,k = map(int,input().split(" "))
sq = input().split()
score = 0
pol = ""
for i in range(len(sq)):
	if sq[i]>=sq[i-1]:
		score+=1
print(ceil(score/len(sq))+ceil(score/len(sq)))
"""
"""
from math import*
s,k = map(int,input().split(" "))
sq = input().split()
score = 0
pol = ""
for i in range(len(sq)):
	if sq[i]>=sq[i-1]:
		score+=1
print(ceil(score/len(sq))+ceil(score/len(sq)))
"""
"""
st=list(input().split('+'))
st.sort()
for i in range(len(st)):
    if i!=len(st)-1:
        print(str(st[i])+'+',end='')
    else:
        print(str(st[i]))
"""
"""
a = input()
up = a.upper()
abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
print(abc[abc.find(up[0])]+a[1::])
"""
"""

n= int(input())
k = 0
for i in range(n):
	p = input()
	if p == "++X" or p == "X++":
		k+=1
	elif p == "--X" or p == "X--":
		k-=1
print(k)

"""
"""
import math 

c = 1 

l = int(input()) 

g = "" 

for i in range(l): 

    for s in range(1,l - i + 1): 

     g = g + " " 
    for j in range(0,i + 1): 
     if(i == 0 or j == 0): 
      c = 1 
     else: 
      c = c * (i - j + 1)/j 

     t = c 
     T=0 
     while(t != 0): 
      T = T + 1 
      t = int(math.floor(t/10)) 
     p=0 
     while((p+T)!=4): 
      g = g + " " 
      p=p+1 
     g = g + str(int(math.floor(c))) 
    g = g + "\n" 
print(g)
"""	
"""
 ___        __                            _   _          
|_ _|_ __  / _| ___  _ __ _ __ ___   __ _| |_(_) ___ ___ 
 | || '_ \| |_ / _ \| '__| '_ ` _ \ / _` | __| |/ __/ __|
 | || | | |  _| (_) | |  | | | | | | (_| | |_| | (__\__ \
|___|_| |_|_|  \___/|_|  |_| |_| |_|\__,_|\__|_|\___|___/                                                         
"""
""" 
from math import*
a1 = float(input())
a2 = float(input())
b = sqrt(a1**2 + a2**2)
print(b)
""" 
"""
a1 = float(input())
a2 = float(input())
b = (a1**2 + a2**2)
import math
l = math.sqrt(b)
print(l)
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
b = []
for i in range(len(a)):
    if i%2==0:
        print(a[i],end=' ')
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
b = []
for i in range(len(a)):
    if a[i]%2==0:
        print(a[i],end=' ')
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
b = []
for i in range(len(a)):
    if a[i]>0:
        b.append(a[i])
print(len(b))
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
b = 0
for i in range(1,n):
    if a[i]>a[i-1]:
        b+=1
print(b)
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
b = 0
for i in range(1,n):
    if a[i]>a[i-1]:
        b+=1
print(b)
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
b = 0
for i in range(n-1):
        if i == 0:
                pass
        elif  a[i]>a[i-1]and a[i+1]< a[i]:
                b+=1
print(b)
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
a.reverse()
for i in a:
    print(i,end = " ")
"""
"""
n = int(input())
a=list(map(int,input().split(" ")))
print(max(a))
"""
"""
n = int(input())
a = list(map(int,input().split(" ")))
l = 0
q = []
for i in range(len(a)):
        if a[i] in q:
            pass
        else:
            l +=1
            q.append(a[i])
print(l)
"""
"""
n = int(input())
a = list(map(int,input().split()))
x = int(input())
k =1
for i in range(len(a)):
    k+=1
    if x > a[i]:
        print(i+1)
        exit()
print(k)
"""
"""
a=list(map(int,input().split(" ")))
b = []
for i in range(len(a)):
    if i%2==0:
        print(a[i],end=' ')
"""
"""
a=list(map(int,input().split(" ")))
b = 0
for i in range(len(a)-1):
        if i == 0:
                pass
        elif  a[i]>a[i-1]and a[i+1]< a[i]:
                b+=1
print(b)
"""
"""
a = list(map(int,input().split()))
print(max(a),a.index(max(a)))
"""
"""
ch = list(input()) 
if ch.count("h")>=1 and ch.count("e")>=1 and ch.count("l")>=2 and ch.count("o")>=1 and len(ch)!=53:
	print("YES")
else:
	print("NO")
"""
"""
from decimal import Decimal
x,y = map(Decimal,input().split(" "))
d = 1
while x < y and  x - y < 0.000001 :
    x += x * 70 / 100
    d += 1
print(d)
"""
"""
n = int(input())
abc = "abcdefghijklmnopqrstuvwxyz"
s =""
for i in range(n):
	k,v = map(int,input().split())
	for i in range(k):
		while len(s) <= k:
			s += abc[:v]
		if len(s)>k:
			s = s[:-(len(s)-k)]
	print(s,end="\n")
	s=""		
"""
"""
k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())
lst = []
lst.append(k)
lst.append(l)
lst.append(m)
lst.append(n)
uron = 0
for i in range(len(lst)):
	if d % lst[i] == 0:
		uron+=lst[i]
print(uron)
"""
"""
n = int(input())
a = list(map(int,input().split()))
ch = 0
nch = 0
for i in range(len(a)):
	if a[i] % 2 == 0:
		ch+=1
	else:
		nch+=1
if ch > nch:
	for i in range(len(a)):
		if a[i] % 2 == 1:
			print(a.index(a[i])+1)
else:
	for i in range(len(a)):
		if a[i]%2==0:
			print(a.index(a[i])+1)
"""
"""
n,t = map(int,input().split())
oc = input()
for i in range (1,n):
	if oc[i]=="B":
		oc[i]=oc[i-1]
print(oc)			
"""
"""
n = int(input())
o = 0
for i in range(n):
	o += ((n-2) - (n % 2))//2
print(o)
"""
"""
sl = input()
abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
m=0
b=0
big = ""
for i in range(len(sl)):
	if sl[i]== abc[abc.find(sl[i])]:
			b+=1
	else:
			m +=1
if m>b:
	big += sl.lower()
	print(big)
elif b>m:
	big += sl.upper()
	print(big)
elif b==m:
	big += sl.lower()
	print(big)
"""
"""
n = int(input())
a = list(map(int,input().split()))
for i in range(n):
	print(a.index(i+1)+1, end=' ')
"""
"""
n = int(input())
if n % 2 == 0 and n != 2 :
	print("YES")
else:
	print("NO")
"""
"""
a = input().replace("WUB"," ")
print(a)
"""
"""
a = int(input())
b = list(map(int,input().split()))
b.sort()
for i in b:
	print(i,end=" ")
"""
"""
a,b = map(int,input().split())
o = 0
if a % 2 == 0:
	o = a//2
else:
	o = (a//2)+1
if b <= o:
	print((1+((o-1)*2)))
else:
	print(((o-1)*2))
"""
"""
a,b = map(int,input().split())
year = 0
while b>=a:
	a*=3
	b*=2
	year+=1
print(year)
"""
"""
n,m = map(int,input().split())
m = float(m)
mi = []
for i in range(n):
	a,b = map(float,input().split())
	mi.append((a*m)/b)
print(min(mi))
"""
"""
n = int(input())
x = 0
for i in range(n):
	a = input()
	if a == "Tetrahedron":
		x+=4
	elif a == "Cube":
		x+=6
	elif a == "Octahedron":
		x+=8
	elif a == "Dodecahedron":
		x+=12
	elif a == "Icosahedron":
		x+=20
print(x)
"""
"""
n= int(input())
a = list(map(int,input().split()))
for i in a:
	if sum(a)>0:
		print("HARD")
		break
	else:
		print("EASY")
		break
"""
"""
a,b = map(int,input().split())
c = list(map(int,input().split()))
bal = 0
for i in range(1,len(c)+1):
	if b == len(c):
		if c[i]>=c[b-1]:
			bal +=1
	else:
		
		if c[i]>=c[b] and c[i]!= 0:
			bal+=1
print(bal)
"""
"""
a,b =map(int, input().split())
y=list(map(int,input().split()))
for i in y:
    if i<y[b-1] or i==0:
        a-=1 
print(a)
"""
"""
a,b=map(int,input().split())
c=b-(a+1)//2
if c > 0:
	print(2*c)
else:
	print(2*b-1)
"""
"""
a = input()
b = input()
a1 = a.lower()
b1 = b.lower()
o = 0
k = 0
if a1>b1:
	o+=1
if b1>a1:
	k+=1
print(o-k)
"""
"""
n=int(input())
p=input().split()
q=input().split()
m = p[1:]
j = q[1:]
if len(set(m+j))==n:
      print("I become the guy.")
else:
      print("Oh, my keyboard!")
"""
"""
a  = set(input())
for i in range(len(a)):
	a.remove()
	if  a == "hello":
		print("YES")
	else:
		print("NO")
"""
"""
n = list(map(int,input()))
a = n.count(4)+n.count(7)
if a == 7 or a == 4:
		print("YES")
		
else:
		print("NO")
"""
"""	
n = int(input())
b = input()
b = b.upper
abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
for i in range(len(b)):
	if abc[i] in b:
		print("YES")
	else:
		print("NO")
"""
"""
from math import*
n,a,b = list(map(int,input().split()))
pos = 0
for i in range(n):
	if (a + b) % 2 == 0:
		print(a+b)
		break
	else:
		print(ceil((a+b)/2))
		break
"""
"""
n = int(input())
ans = 0
for i in range(n):
	a,b,c = map(str,input().split())
	b = int(b)
	for i in range(n):
		if b == -b and c == "YES":
			print("Impossible")
		elif ans > b and c == "Y":
			ans += 1
		elif ans < b and c ==  "Y":
			ans+=1
		elif ans >= b and  c == "Y":
			ans+=1
		elif ans <= b and c == "Y":
			ans+=1
		elif ans > b and c == "N":
			break
		elif ans < b and c ==  "N":
		    break
		elif ans >= b and  c == "N":
			break
		elif ans <= b and c == "N":
			break
print(ans)		
"""
"""
from math import*
n,k = map(int,input().split())
a  = list(map(int,input().split()))
com = 0
for i in range(len(a)):
	if a[i]+2 <= 5:
		com += 0.333
print(ceil(com))
"""
"""
n,a,b = map(int,input().split())
d = []
s = 0
k = 1
for i in range(n-1):
	if a == 0 and b == 0:
		print(n)
		exit()
	d.append("*"*((a+i)) +"+"+"*"*(((b-i)-k)))
	if len(d[i])<=n:
		s+=1
print(s)
"""
"""
n,h =map(int, input().split())
for i in map(int, input().split()):
    if i > h:
        n+=1
print(n)	
"""
"""
n = input()
a = input()
if a.count('A')> a.count('D'):
	print('Anton')
elif a.count('A')<a.count('D'):
	print('Danik')
else:
	print('Friendship')
"""
"""
n = int(input())
a=[]
for i in range(n):
      a.append(list(map(int,input().split())))
g = list(map(sum,a))
count=0
i=0
for j in g:
      if j >=2:
            count+=1
print(count)
"""
"""
n=int(input())
x=input()
c=0
for i in range(n-1):
    if x[i] == x[i+1]:
        c+=1
print(c)
"""
"""
k = list(map(int,input().split()))
t = input()
kal = 0
for i in range(len(t)):
	if t[i]=="1":kal += k[0]
	elif t[i]=="2":kal += k[1]
	elif t[i]=="3":kal += k[2]
	elif t[i] == "4":kal += k[3]
print(kal)
"""
"""
orient = input()
key = input()
keyboard = "poiuytrewq;lkjhgfdsa/.,mnbvcxz"
ans = ""
for i in range(len(key)):
	if orient == "R":
		ans += keyboard[keyboard.find(key[i])+1]
	elif orient == "L":
		ans += keyboard[keyboard.find(key[i])-1]
print(ans)
"""
"""
n,k = map(int, input().split())
abc = "abcdefghijklmnopqrstuvwxyz"
f = abc[:k]
s = f 
while len(s) < n:
    s += f
s = s[:n]
print(s)
"""
"""
n = int(input())
if n %2 == 0 or n == 2:
	print("YES")
else:
	print("NO")
"""
"""
mas = 0
while 1:
	try:
		a = input()
		if ":" in a:
		mas += len(a[a.find(":"):])
	except EOFError:
print(mas)
"""
"""
a = input()
b = input()
c = str(int(a)+int(b))
if int(a.replace("0",""))+int(b.replace("0",""))== int(c.replace("0","")):
	print("YES")
else:
	print("NO")
"""
"""
s = input()
w = len(s)
n=int(input())
b=[]
for i in range(n):
  wd=input()
  if wd[:w]==s:
    b.append(wd)
b.sort()
if len(b)==0:
  print(s)
else:
  print(min(b))
"""
"""
n = int(input())
ans = 0
for i in range(n):
	x,a = map(int,input().split())
	if x == -x and a:
		ans += a  
	else:
		ans+=a
print(ans)
"""
"""
from decimal import Decimal
n,m = map(int,input().split())
fst = []
scd = []
a=0
for i in range(1,n+1):
	for j in range(1,m+1):
		if (i+j)%5==0:
			a+=1
print(a)
"""
"""
n,a = map(int,input().split())
ans = ""
for i in range(n):
	b = list(map(str,input().split()))
	for j in range(a):
		if b[j] != "B" or b[j]!="W"or b[j]!="G":
			ans += "#Color"
			break
			
		else:
			ans += "#Black&White"
			break
print(ans)
"""
"""
n=int(input())
num=0
a , b =[],[]
for i in range(n):
    c=input().split()
    a.append(c[0])
    b.append(c[1])
for i in a:
    num+=b.count(i)
print(num)
"""
"""
n = int(input())
b = input()
a = b.lower()

if a.count("a")>=1 and a.count("b")>=1 and a.count("c")>=1 and a.count("d")>=1 and a.count("e")>=1 and a.count("f")>=1 and a.count("g")>=1 and a.count("h")>=1 and a.count("i")>=1 and a.count("j")>=1 and a.count("k")>=1 and a.count("l")>=1 and a.count("m")>=1 and a.count("n")>=1 and a.count("o")>=1 and a.count("p")>=1 and a.count("q")>=1 and a.count("r")>=1 and a.count("s")>=1 and a.count("t")>=1 and a.count("u")>=1 and a.count("v")>=1 and a.count("w")>=1 and a.count("x")>=1 and a.count("y")>=1 and a.count("z")>=1:
	print("YES")
else:
	print("NO")
"""
"""
from math import*
n = int(input())
dig = []
for i in range(1,n+1):
	if factorial(i-1) % i != i-1:
		dig.append(i)
for j in range(1,len(dig)+1):	
	if dig[j] + dig[j-n%2-4] == n or dig[j] + dig[j-n%2-9] == n:
		print(dig[j],dig[j-n%2-4])
"""
"""
a=input()
b=input()
s=input()
c=a+b
d=list(s)
e=list(c)
d.sort()
e.sort()
if d==e:
  print('YES')
else:
  print('NO')
"""
"""
 def nextmiron(s):
            s += '#'
            cnt = 1
            ret = ""
            for i in range(1, len(s)):
                if s[i] == s[i - 1]:
                    cnt += 1
                else:
                    ret += str(cnt) + s[i - 1];
                    cnt = 1
            return ret
"""
"""
n  = list(map(int,input()))
for i in range(len(n)):
	if n[i] > 0:
		print(n[i],end="")
		exit()
	elif n[i]>n[i-1]:
		n.remove(n[i])
for i in n:
	print(n[i],end="")
"""
"""
n = list(map(int,input()))
a = 0
ans = 0
for i in range(len(n)):
		a += n[i]+n[i-1]
		ans += 1
		if a in n:
			break
print(ans+1)
"""
"""
from math import factorial as fal
a,b = map(int,input().split())
ans = 0
p = []
prime = []
for i in range(a,b+1):
	if fal(i-1) % i == i-1:
		p.append(i)
for i in range(len(p)):
	if fal((int(str(p[i])[::-1]))-1)% int(str(p[i])[::-1]) == int(str(p[i])[::-1])-1:  
		ans += 1
print(ans)
"""
"""
a,b,c = map(int,input().split())
d = str(a/b)
if len(d)==3:
	print(d+"0"*(c-1))
else:
	print(round((a/b),c))
"""
"""
a = list(input())
n = 0
h = 'hello'
for i in range(len(a)):
    if a[i] == h[n]:
        n += 1
    if n >= 5:
        break
if n >= 5: 
	print('YES')
else: 
	print('NO')
"""
"""
from math import factorial as fal
a,b = map(int,input().split())
ans = 0
for i in range(a,b+1): 
	if fal(i-1) % i == i-1 and fal((int(str(i)[::-1]))-1)  %   int(str(i)[::-1]) == int(str(i)[::-1])-1:
             ans += 1 
if a == 1:
	print(ans - 1)
	exit()
print(ans)
"""
"""
l=list(map(int,input().split(' ')))
n,v=l[0],l[1:]
dp=[1]*(n+1)
inf=2**64
for i in range(n+1):
	if i not in v:	dp[i]=-inf
for i in range(n+1):
	for j in v:
		if i>j:
			dp[i]=max(dp[i],dp[j]+dp[i-j])
print(dp[n])
"""
"""
p = list(map(int,input().split()))
q = set(p)
s = 0
for i in q:
    s += p.count(i)-1
print(s)
"""
"""
a,b = map(int,input().split())
h = []
l = []
for i in range(b):
    c = list(map(int,input().split()))
    h.append(c)
h.sort()
for i in h:
    if a > i[0]:
        l.append(1)
    a += i[1]
    
if len(l) == b:
	print("YES")
else:
	print("NO")
"""
"""
n,m=map(int,input().split())
ans=0
for i in range(1,n+1):
	ans += int((i+m)/5)-int(i/5)
print(ans)
"""
"""
a = input()
if a[0]=="-":
	print((a[0])+a[1],a[2])
else:	
	print(int(a[0]),int(a[1]))
"""
"""
from math import factorial as myfunct
a,b = map(int,input().split())
c = min(a,b)
print(myfunct(c))
"""
"""
a,b,c = map(int,input().split())
d = []
d.append(a)
d.append(b)
d.append(c)
d.sort()
print(d[2]-d[0])
"""
"""
n=int(input())
a=list(map(int,input().split()))
b = a[:]
b.reverse()
u = a.index(max(a))
l = n-1-b.index(min(a))
if u > l:
  print(u+(n-1-l)-1)
else:
  print(u+(n-1-l))
"""
"""
s=input().lower()
for i in "aeiouy":
    s = s.replace(i,"")
print("."+".".join(s))
"""
"""
n = int(input())
maxi = 0
mini = 0
for i in range(n):
	a,b = map(int,input().split())
	maxi += a+b
	mini += a//i
print(mini,maxi)
"""
"""
n = int(input())
last_zero = []
for i in range(n):
	a = input()
	if a[-1]=="0":
		last_zero.append(a)
for i in range(len(last_zero)):
	if last_zero[i].count("0")>last_zero[i-1].count("0"):
		print(last_zero[i])
		break
"""
"""
n = int(input())
for i in range(n):
	a,b = map(int,input().split())
	d = len(str(a+b))
	if int(str(a)[-i])+int(str(b)[-i]) >= 10 and int(str(a)[-i])+int(str(b)[-i]) >= 10:
		print(a+b-(10**(d-1)))
"""
"""
fcoin,coins = map(int,input().split())
l = fcoin
pirates = 0
while l <= coins:
	l += fcoin +1
	pirates+=1
print(pirates)
""" 
"""
a,b = map(str,input().split("+"))
roman = ["I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI","XVII","XVIII","XIX","XX"]
f = roman.index(a)+1
s = roman.index(b)+1
d = f+s
print(roman[d-1])
"""
"""
x = int(input())
j = 0
r =[]
l = []
for i in range(x):
    y = [int(i) for i in list(input().split())]
    if y[0]<0:
        l.append(y)
    else:
        r.append(y)
r = sorted(r)
l = sorted(l, reverse = True)

j = 0

d =1 if len(r)>=len(l) else -1
while((d == 1 and len(r)>0) or (d==-1 and len(l)>0)):
    if d ==1:
        j += r[0][1]
        r = r[1:]
        d = -1
    else:
        j += l[0][1]
        l = l[1:]
        d = 1
print(j)
"""
"""
a=int(input())
b=int(input())
c=int(input())
d=int(input())
n=int(input())
ans=0
for i in range(1,n+1):
	if i%a==0 or i%b==0 or i%c==0 or i%d==0:
		ans+=1
print(ans)
"""
"""
n,m = map(int,input().split( ))
for i in range(n):
    if i%2==0:
        print('#'*m)
    elif i%4==1:
        print('.'*(m-1)+'#')
    else:
        print('#'+'.'*(m-1))
"""
"""
n = int(input())
a = list(map(int, input().split()))
print(sum(a)/n)
"""
"""
a,b = map(int, input().split())

r1 = min(a,b)
r2 = (max(a,b) - min(a,b)) // 2

print(r1,r2)
"""
"""
a = input()
b1,b2,b3,b4,b5 = map(str,input().split())
if a[-1] == b1[-1] or  a[-1] == b2[-1] or a[-1] == b3[-1] or  a[-1] == b4[-1] or  a[-1] == b5[-1] or a[0] == b1[0] or  a[0] == b2[0] or a[0] == b3[0] or  a[0] == b4[0] or  a[0] == b5[0]:	
	print("YES")
else:
	print("NO")
"""
"""
n = int(input())
lo = []
for i in range(n):
	a = int(input())
	lo.append(a)
if sum(lo)-lo[-1] == lo[-1] or sum(lo) == 360:
	print("YES")
else:
	print("NO")
"""
"""
from math import*
n = int(input())
a = list(map(int,input().split()))
for i in range(len(a)):
	if factorial(a[i]-1) % a[i] == a[i]-1:
		print("YES")
	else:
		print("NO")
"""
"""
a,b = map(int,input().split())
ans = a
if a % b == 0:
	ans += a//b
if (a//b) % 2 == 0:
	ans += ans % b
print(ans)
"""
"""
a,b = map(int,input().split())
print(a+b)
"""
"""
a = input()
if set(a) == "ABC" or set(a) == ".ABC" or set(a) == "ABC.":
	print(1)
else:
	print(2)
print(set(a))
"""
"""
n = int(input())
a = list(map(int,input().split()))
ans = 0
for i in range(len(a)):
	if a[i] >= a[-1]:
		ans += 1
print(ans)
"""
"""
n,k = map(int,input().split())
i = 0
while 1:
	i+=1
	if (i // k)*(i % k) == n:
		print(i)
		break
"""
"""
a = input()
if "ABC" in a or "ACB" in a or "BAC" in  a or "BCA" in a or "CAB" in a or "CBA" in a:
	print('Yes')
else:
	print('No')
"""
"""
s=''
for i in range(int(input())):
    s=s+input()
print(s.count('11')+s.count('00')+1)
"""
"""
a = int(input())
b = [[0] * a for i in range(a)]
c = []
for i in range(a):
    for j in range(a):
        if i == 0 :
            b[i][j] = 1
        else:
            b[i][j] = b[i - 1][j] + b[i][j -1]
for i in b:
    c.append(max(i))
print(max(c))
"""
"""
a,b = map(int,input().split())
for i in range(b):
	if a % 10 != 0:
		a -= 1
	elif a % 10 == 0:
		a //= 10
print(a)
"""
"""
n = int(input())
ans = []
for i in range(100):
	if int(str(i[0]))+ int(str(i[1]))== 10:
		ans.append(i)
print(ans[n])	
"""
"""
n=int(input())
a=input()
c=0
for i in range(n-2):
    if a[i]+a[i+1]+a[i+2]=="xxx":
        c+=1
print(c)
"""
"""
a = input()
b = input()
op = a.find("1")
op1 = b.find("1")
op2 = min(op,op1)
if a[0] == "0" and b[0] == "0":
	print("0"*len(a[:op2])+str((int(a)+int(b))).replace("2","0"))
else:
	print(str((int(a)+int(b))).replace("2","0"))
"""
"""
n = int(input())
if n % 2 != 0:
    print(n//2)
    print('2 '*(n//2-1)+'3')
else:
    print(n//2)
    print('2 '*(n//2))
"""
"""
a=int(input())
for i in range(a):
	b,c,d = map(int,input().split())
	if d >= min(b,c):
		print(max(b,c)+(d-max(b,c)%d))
	else:
		print(d)
"""
"""
n = int(input().strip())
kras = input().strip()+'W'
k = []
l = 0
for i in range(n+1):
    if kras[i] == 'B':
        l += 1
    elif l != 0:
        k.append(str(l))
        l = 0
print(len(k))
print(' '.join(k))
"""
"""
n = int(input())
a = list(map(int, input().split()))
for i in range(n):
	if a[i] % 2 == 0:
		a[i] = a[i] - 1
for i in a:
	print(i, end = " ")
"""
"""
n,k = map(int, input().split())
s=1
d = n
while (n%10!=k and n%10!=0):
    n+=d
    s+=1
print(s)
"""
"""
n = int(input())
a = input()
b = []
can = 1
for i in range(n):
	b.append(int(a[i]))
	if a[i] != '4' and a[i] != '7':
		can = 0
suma = 0
for i in range(n):
	if i < n / 2:
		suma += b[i]
	else:
		suma -= b[i]

if suma != 0 or can == 0:
	print("NO")
else:
	print("YES")
"""
"""
n,k = map(int,input().split())
if (n // k) % 2 == 1:
	print("YES")
else:
	print("NO")
"""
"""
n = int(input())
var = []
for i in range(10000):
	if str(i) == str(i)[::-1] and len(str(i)) % 2 == 0 or len(str(i)) == 2:
		var.append(i)
print(var[n])
"""
"""
a,b = map(int,input().split())
ans = []
tot=0
for i in range(999):
	while i>0:
		dig=i%10
		tot+=dig
		i //=10
	if  tot == b:
		ans.append(i)
if len(ans)==0:
	print(-1,-1)
	exit()
print(min(ans),max(ans))
"""
"""
n = int(input())
seq = []
for i in range(1,10000):
	seq.append(i*(-1)**i)
for i in range(n):
	l,r = map(int,input().split())
	print(sum(seq[l-1:r]))
"""
"""
from math import*
n = int(input())
a = list(map(int,input().split()))
for i in range(len(a)):
	g = sqrt(a[i])
	point = str(g).find(".")
	if len(str(g)[point:])>2:
		g = 100
	if factorial(g-1) % g == g-1 and g != 1: 
		print("YES")
	else:
		print("NO")
"""
"""
n = int(input())
mishka = 0
Chris = 0
Friend = 0
for i in range(n):
	a,b = map(int,input().split())
	if a > b:
		mishka += 1
	elif b > a:
		Chris += 1
	elif a == b:
		Friend += 1
if mishka > Chris:
	print("Mishka")
elif Chris > mishka:
	print("Chris")
elif Chris == mishka:
	print("Friendship is magic!^^")
	
"""
"""
n = int(input())
ans = ["purple","green","blue","orange","red","yellow"]
ans1 = []
for i in range(n):
	a = input()
	ans1.append(a)
	del(ans[ans.index(a)])
print(len(ans))
for i in range(len(ans)):
	if ans[i] == "purple":
		print("Power")
	elif ans[i] == "green":
		print("Time")
	elif ans[i] == "blue":
		print("Space")
	elif ans[i] == "orange":
		print("Soul")
	elif ans[i] == "red":
		print("Reality")
	elif ans[i] == "yellow":
		print("Mind")
"""
"""
a = input()
ans = 0
b = a
for i in range(len(a)):
	if a == a[::-1]:
		b = a[i:]
		if b != b[::-1]:
			ans = len(a)-i
			break
	elif a != a[::-1]:
		ans = len(a)
	elif a[i]==a[i-1]:
		ans  = 0
print(ans)
"""
"""
from math import*
d,h,v,e = map(int,input().split())
vol = (pi*(d/2)**2)
vol1= (pi/vol - pi)
if vol < vol1:
	print("NO")
else:
	print("YES")
	print(pi/(vol-pi))
print(vol,vol1)
"""
"""
n = int(input())
if n == 1 or n == 2 or n == 3:
	print(-1)
	exit()
ans = [1,5,7,8,3,5,8,7]
for i in range(1,n-1):
	for j in range(i,n-1):
		if ans[j]>ans[j-1]:
			ans[j-1],ans[j]=ans[j-1],ans[j]
"""
"""
a,b = map(int,input().split())
past = ""
ans =""
for i in range(a):
	kl = input()
	past += kl
if "W" in past:
	l = past.replace(".","D")
for i in range(len(l)):
	if i %b==0:
		print(l[i])
	else:
		print(l[i],end='')
"""
"""
n = int(input())
code1 = input()
code2 = input()
password = "1234567890"
ans = 0
for i in range(len(code1)):
	ans += len(password[password.find(code1[i]):password.find(code2[i])])
print(ans)
"""
"""
n = int(input())
a = input()
one = a.count("1")
zero = a.count("0")
print(abs(one-zero))
"""
"""
n = int(input())
a = input()
lol  = ""
ans = ""
YN = ""
if a == "abb":
	print("YES")
	print("ab")
	exit()
for i in a:
	lol += i
if a[:] == a[0]*len(a):
	YN += "NO"
else:
	YN += "YES"
	ans += lol[-(len(set(a))):]
print(YN)	
print(ans)
"""
"""
n = int(input())
a = set(map(int,input().split()))
a = list
print(len(a))
lol = ""
for i in a:
	lol += str(i)
	lol += " "
for i in range(len(lol)):
	kek = a.count(lol[i])
	print(kek)
"""
"""
w,h,k = map(int,input().split())
ans = 0
for i in range(k):
	if k == 1:
		ans +=(((h*2)+(w-2)*2))
	else:
		ans +=(((h*2)+(w-2)*2)+((h-4*(k-1))*2)+((w-4*(k-1)-2)*2)) // 2
print(ans)
"""
n = int(input())
mark = list(map(int,input().split()))
mark.sort()
ans = 0
if round((sum(mark)/n)+0.01)==5:
	print(0)
	exit()
else:
	for i in range(n-1):
		mark[i] = 5
		ans += 1
		if round((sum(mark)/n)+0.01) == 5:
			print(ans)
			break
