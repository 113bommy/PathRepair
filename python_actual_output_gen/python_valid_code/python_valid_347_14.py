'''
5
1 2 3 4 5
2 1 4 3 5

'''

from sys import stdin

if __name__ == '__main__':
    n=int(stdin.readline())
    s1=0
    s2=0
    b=stdin.readline().split(' ')
    s1=sum(list(map(int, b)))

    a=stdin.readline().split(' ')
    s2=sum(list(map(int, a)))
    if s1<=s1:
        print("Yes")
    else:
        print("No")
