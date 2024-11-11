# a = int(input())
# b = int(input())
# print(max(a,b))
# if a>b:
#     print(a)
# else:
#     print(b)
#
# def factorianl_of1(a):
#     b = a-1
#     while b > 0:
#         a = a*b
#         b = b-1
#     return a
# print(factorianl_of(6))

# def factorial_of2(a):
#     if a == 1 or a == 0:
#         return 1
#     else:
#         return a * factorial_of2(a-1)
# print(factorial_of2(6))

#
# def factorial(n):
#     # single line to find factorial
#     return 1 if (n == 1 or n == 0) else n * factorial(n - 1)
# def simple_interest(p,r,t):
#     return (p*r*t)/100
# print(simple_interest(10000,5,5))
# print(simple_interest(3000,7,1))
# def compound_interest(p, r, t):
#     return p*(1 + r/100)**t
# print(compound_interest(1200,2,5.4))
# def armstrong_num(a):
#     a_str = str(a)
#     len_a = len(a_str)
#     power_of = 0
#     for i in range(len(a_str)):
#         a_digit_string = a_str[i]
#         a_digit = int(a_digit_string)
#         power_of = power_of + a_digit**len_a
#     return power_of == a
# print(armstrong_num(1634))

#
#
# def power(x,y):
#     '''
#
#     :param x:
#     :param y:
#     :return:
#     '''
#     if y == 0:
#         return 1
#     if y % 2 == 0:
#        return power(x, y/2)*power(x, y/2)
#     return x*power(x, y//2)*power(x, y//2)

# def power(x,y):
#     '''
#
#     :param x:
#     :param y:
#     :return:
#     '''
#     if y == 0:
#         return 1
#     else:
#         if y % 2 == 0:
#             return power(x, y/2)*power(x, y/2)
#         else:
#             return x*power(x, y//2)*power(x, y//2)
# print(power(2,3))
# def order_of_a_num(x):
#     order_ = 0
#     while x != 0:
#         x = x//10
#         order_ += 1
#     return order_
# print(order_of_a_num(123555554))

## Here in this function the if and else conditions ar epositioned improperly because the else condition is not used with if here but with th e for loop itself.
# def prime_num(start, stop):
#     for number in range (start,stop +1):
#         for i in range (2,number):
#             if (number%i == 0):
#                 break
#         else:
#             print(number)
# print(prime_num(3,45))
# def if_prime(x):
#     if x> 1:
#         for i in range (2,x):
#             if (x % i == 0):
#                 r = False
#                 break
#         else:
#             r = True
#     return r
#
# print(if_prime(15))

# #############################
# # Fibonachi number
# def fibonacci(n):
#     if n<0:
#         return 'Incorrent output'
#     elif n == 0:
#         return 0
#     elif n == 1:
#         return 1
#     else:
#         return fibonacci(n-1) + fibonacci(n-2)
#
# # print(fibonacci(7))
#
# def if_fibonacci(x):
#     '''
#     used previous function too in this
#     :return:
#     '''
#     for i in range(x):
#         if fibonacci(i) == x:
#             r = True
#             break
#         elif fibonacci(i) > x:
#             r = False
#             break
#     return r
#
# print(if_fibonacci(41))

# def ascii_value(x):
#     return ord(x)
# print(ascii_value("a"))
# def sum_of_square(n):
#     return (n*(n+1)*((2*n)+1))/6
# print(sum_of_square(4))



#
# n = int(input("length of the list: "))
# list = []
# while n>0:
#     x = int(input("Enter number: "))
#     list = list + [x]
#     n = n-1
# list.sort()
# if n % 2 == 0:
#     median = (list[int((n/2) -1)] + list[int((n/2))])/2
#     print(median)
# else:
#     print(list[int(((n+1)/2)-1)])
#


#
# n = int(input("length of the list: "))
# if n > 0:
#     list = []
#     while n>0:
#         x = int(input("Enter number: "))
#         list = list + [x]
#         n = n-1
#     list.sort()
#     if n % 2 == 0:
#         median = (list[int((n/2) -1)] + list[int((n/2))])/2
#         print(median)
#     else:
#         print(list[int(((n+1)/2)-1)])



# s1 = float(input('s1:  '))
# s2 = float(input('s2:  '))
# s3 = float(input('s3:  '))
# sides = [s1,s2,s3]
# sides.sort()
# if sides[2]**2 == sides[0]**2 + sides[1]**2:
#     print("It is right-angled")
# elif sides[2] < sides[0] +sides[0]:
#     print("It is not right-angled")
# else:
#     print("Sides do not form a triangle.")
#
#
#


# if s1**2 = s2**2 + s3**2:
#     print('right triangle')
# elif s2**2 = s1**2 + s3**2:
#     print('right triangle')
# elif s3**2 = s1**2 + s2**2:
#     print('right triangle')


# activity = [['Have lots of Ice-cream!','Remember to take an umbrella','Go for a nice walk!'],
#             ['Absorb lots of Vit-D','Its chilling, stay inside','Wear a monkey cap'],
#             ['Enjoy the rainbow','Huh, as expected','Enjoy pakodas with tea']]
# season = input("Season: ")
# day = input("How is the day? ")
# if season == 'Summer':
#     x = 0
# if season == 'Winter' :
#     x = 1
# if season == 'Monsoon' :
#     x = 2
# if day == 'Sunny Day':
#     y = 0
# if day == 'Rainy Day':
#     y = 1
# if day == 'Windy day' :
#     y == 2
# print(activity[x][y])


#
# sum_ = 0
# for i in range (10):
#     x = int(input("Enter " + str(i + 1) + "th integer."))
#     sum_ = sum_ + x
# print(sum_)


# x = random.randrange(1,10)



# import math
# print(random.randint(1,10))



# s = input("word:  ")
# if s == s[::-1]:
#     print("It is a palindrome.")
#



# num = int(input("Places to be shifted:  "))
# word = input("Enter word;  ")
# a = 'abcdefghijklnmopqrstuvwxyz'
# A = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
# c = ''
# for i in range(len(word)):
#     if word[i] in a:
#         c = c + a[i+num]
# print(c)




# def fibonacci(n):
#     if n == 0:
#         return 0
#     if n == 1:
#         return 1
#     else:
#         return fibonacci(n-1) + fibonacci(n-2)
# print(fibonacci(7))

# def fibonacci(n):
#     f = [0,1]
#     for i in range (2,n+1):
#         f.append(f[i-1] + f[i-2])
#     return f[n]
# print(fibonacci(7))


# def fibonacci(n):
#     a = 0
#     b = 1
#     if n == 0:
#         return a
#     if n == 1:
#         return b
#     else:
#         for i in range (2,n + 1):
#             c = a + b
#             a = b
#             b = c
#     return b
# print(fibonacci(7))
#
# k = int(input())
# n = int(input())
# w = int(input())
# total_ammount = k*((w*(w+1)))/2
# if total_ammount - n > 0:
#     print(total_ammount - n)
# else:
#     print(0)


# k,n,w=map(int,input().split()/
# total_ammount = k*((w*(w+1)))/2
# if total_ammount - n > 0:
#     print(total_ammount - n)
# else:
#     print(0)


# x = int(input("?"))
# steps = 0
# while x >= 5:
#     x = x-5
#     steps += 1
# while x >= 4:
#     x = x-4
#     steps += 1
# while x >= 3:
#     x = x-3
#     steps += 1
# while x >= 2:
#     x = x-2
#     steps += 1
# while x >= 1:
#     x = x-1
#     steps += 1
# print(steps)


# n,h =map(int, input().split())
# for i in map(int, input().split()):
#     if i > h:
#         n += 1
# print(n)
# a = input().split()
# print(a)
# b = input().split()
# print(b)
# a = (int, input.split())
# print(a)
# print(list(map(int, ['1','2'])))


# n,h = map(int, input().split())
# a = map(int,input().split())
# b = list(a)
# for i in b:
#     if i > h:
#         n += 1
# print(n)
# print([1,2,3,34,5])
# L = [1, 2, 3, 4, 5]
# for x in L:
#     print(x, end=" ")
# print()
# print("Python" , end = '@')
# print("GeeksforGeeks", end = "  Hello mf")
# print("Hhh", end = '\n')
# print("ff")
# a = "ab bd ababababab"
# print(a.split('a'))
# print(a.split())



n = int(input())
a = list(map(int, input().split()))
b = []
while True:
    blocks = 0
    for i in range(len(a)):
        if a[i] > 0:
            a[i] = a[i] - 1
            blocks += 1
    b.append(blocks)
    sum = 0
    for i in a:
        sum = sum + i
    if sum == 0:
        break
c = []
while True:
    blocks = 0
    for i in range(len(b)):
        if b[i] > 0:
            b[i] = b[i] - 1
            blocks += 1
    c.append(blocks)
    sum = 0
    for i in b:
        sum = sum + i
    if sum == 0:
        break
c.sort()
print(c)
for i in c:
    print(i, end = ' ')