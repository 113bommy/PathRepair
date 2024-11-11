'''
# CodeForce Equalize Prices 900 points

# a = old price / b = new price / k =value input
def Computer_Game():

    for _ in range(int(input())):
        k, n, a, b = map(int, input().split())  # init charge, num turns in game, a,b bat value
        max_turns=0
        for turns in range(n):

            if k/b > n and (k-a)/b < n-1 and turns == 0:
                max_turns=0
                break
            else:
                if k > a:
                    k -= a
                    max_turns += 1
                elif k > b:
                    k -= b
                    if k/b == n-turns:
                        max_turns = 1
                        break
                else:
                    max_turns = -1
                    break


        print(max_turns)


    return


def bit_plus_plus():

    summe = 0
    for _ in range(int(input())):

        statement = input()
        if '+' in statement:
            summe += 1
        else:
            summe -= 1
    print(summe)
    return

def petya_and_strings():

    str_a, str_b = input().lower(), input().lower()
    a=(str_a<str_b)
    print((str_a>str_b)-(str_a<str_b))


    return




def beautiful_matrix():

    for idx in range(5):

        row_input = list(map(int,input().split()))
        if 1 in row_input:
            row = idx+1
            for idx1, elem in enumerate(row_input):
                if elem == 1:
                    column = idx1+1

    output = abs(3 - row) + abs(3 - column)
    print(output)
        #for row_num in range(4):
           # if 1 in row(row_num)

    return


def helpful_maths():


    string = sorted(list(input().split('+')))
    print('+'.join(string))

    return


def word_capitalization():

    string = input()
    string_new = string[0].upper()+string[1:]
    print(string_new)

    return

def Stones_on_the_Table():
    _ = input()
    string=list(input())
    color_old = ''
    color_old_old = ''
    take = 0
    for color in string:

        if color == color_old:
            take += 1
        else:
            color_old = color


    print(take)

    return

def Boy_or_girl():
    print([{*input()}])
    string = input()
    new_string = ''
    for _ in string:
        if _ not in new_string:
            new_string = new_string + _
    if len(new_string) % 2 != 0:
        print('IGNORE HIM!')
    else:
        print('CHAT WITH HER!')

    return


def soldier_and_bananas():

    k,n,w = map(int,input().split())
    prize = 0
    for num in range(w):
        prize = prize + (num+1)*k

    print(prize-n if prize-n > 0 else 0)
    return


def bear_and_big_brother():

    a,b = map(int, input().split())
    years = 0
    while a <= b:
        a = a*3
        b = b*2
        years += 1

    print(years)

    return


def Tram():
    passenger = []
    cur_pass = 0
    for _ in range(int(input())):

        exit_passenger, enter_passenger = map(int,input().split())
        cur_pass = cur_pass - exit_passenger + enter_passenger
        passenger.append(cur_pass)

    print(max(passenger))
    return



def subtract_one(number):

    if float(number)%10 == 0:
        result = number / 10
    else:
        result = number - 1

    return int(result)

def wrong_subtraction():

    n, k = map(int, input().split())

    for _ in range(k):
        n = subtract_one(n)

    print(n)
    return

def wet_shark_and_odd_and_even():

    odd = []
    even = []
    odd_cnt = 0
    n = input()
    numbers = list(map(int,input().split()))
    for number in numbers:
        if number%2 == 0:
            even.append(number)
        else:
            odd.append(number)
            odd_cnt += 1

    odd.sort()
    k = int(odd_cnt/2)*2
    if k > 0:
        summe = sum(even) + sum(odd[-k:])
    else:
        summe = sum(even)
    print(summe)


    return





def sorting(volumes):

    sorting_steps = 0
    idx = 0
    cnt = 0
    while(idx < len(volumes)-1):
        a = volumes[idx]
        b = volumes[idx+1]
        # print(volumes)
        if a > b:
            volumes[idx] = b
            volumes[idx+1] = a
            sorting_steps += 1
            if idx > 0:
                idx -= 1

            else:
                cnt = cnt+1
                idx = cnt

        else:
            idx += 1
    return sorting_steps

def cubes_sorting():

    for _ in range(int(input())):

        n = int(input())
        a = list(map(int,input().split()))

        max_sort = n*(n-1)/2-1

        sorting_steps = sorting(a)

        if sorting_steps > max_sort:
            print('NO')
        else:
            print('YES')


    return

def elephant():

    coord = int(input())
    steps_taken = 0
    for steps in range(5,0,-1):
        if (coord / steps) >= 1:
            steps_taken = int(coord / steps) + steps_taken
            coord = int(coord % steps)
    print(steps_taken)
    return

def queue_at_the_school():
    number, time = map(int,input().split())
    queue=list(input())

    i = 0

    while i < time:
        idx = 0
        while idx < len(queue)-1:
            if queue[idx] == 'B' and queue[idx+1] == 'G':
                queue[idx] = 'G'
                queue[idx+1] = 'B'
                idx += 2
            else:
                idx += 1
        i += 1

    print(''.join(queue))
    return

def nearly_lucky_number():
    number = input()
    l_number = 0
    bla=[sum(i in '47' for i in number) in [4, 7]]
    print('4' in number)
    for elem in number:
        if elem == '7' or elem == '4':
            l_number += 1
    print('YES' if l_number == 4 or l_number == 7 else 'NO')

    return

def word():
    string = input()
    count = 0
    for elem in string:
        if elem.isupper():
            count += 1

    print(string.upper() if count > len(string)/2 else string.lower())

    return
'''
def translation():
    word_1 = input()
    word_2 = input()[::-1]
    print(["NO", "YES"] [word_1 == word_2])


    return

def anton_and_danik():

    games = int(input())
    wins=input()
    anton_wins = sum(i == 'A' for i in wins)
    if anton_wins*2 > len(wins):
        print('Anton')
    elif anton_wins*2 == len(wins):
        print('Friendship')
    else:
        print('Danik')
    return

def acoomodation():

    cnt = 0
    for _ in range(int(input())):
        p, q = map(int, input().split())
        if q - p >= 2:
            cnt +=1

    print(cnt)


    return

def juicer():

    n, b, d = map(int, input().split())

    sum_orange = 0
    cnt_empty = 0
    for orange in list(map(int, input().split())):

        if orange <= b:
            sum_orange += orange
            if sum_orange > d:
                cnt_empty += 1
                sum_orange = 0
    print(cnt_empty)
    return


def digit_game():

    for game in range(int(input())):
        breach_odd_cnt = 0
        breach_even_cnt = 0
        raze_odd_cnt = 0
        raze_even_cnt = 0
        n = int(input())
        number = input()
        breach_numbers = ''
        raze_numbers = ''
        len_number = len(number)

        idx = 1
        for digit in number:

            if idx%2 == 0:
                breach_numbers += digit
                if digit in '13579':
                    breach_odd_cnt += 1
                else:
                    breach_even_cnt += 1
            else:
                raze_numbers += digit
                if digit in '13579':
                    raze_odd_cnt += 1
                else:
                    raze_even_cnt += 1
            idx += 1
        if len_number == 1:
            if int(number)%2 == 0:
                print(2)
            else:
                print(1)
        elif len_number%2 == 0:  # last pick from raze raze lässt eins übrig
            if breach_even_cnt >= 1:
                print(2)
            else:
                print(1)
        else:  # last pick from breach breach lässt übrig
            if raze_odd_cnt >= 1:
                print(1)
            else:
                print(2)

            # raze only odd breach only even 1 = odd 0 = even raze starts
            # 1 raze wins
            # 2 breach wins

    return

def modular_exponentiation():

    n = int(input())
    m = int(input())
    #print(int((0b1 << n)))
    calc = m % int((0b1 << n))
    print(int(calc))

    return

if __name__ == '__main__':

    modular_exponentiation()

'''
if __name__ == '__main__':
    num_queries = int(input())

    for querie in range(num_queries):
        num_products, value_products = map(int, input().split())
        price_products = list(map(int, input().split()))
        B_Max = min(price_products)+value_products
        B_Min = max(price_products)-value_products
        if B_Max >= B_Min:
            print(B_Max)
        else:
            print(-1)
'''






