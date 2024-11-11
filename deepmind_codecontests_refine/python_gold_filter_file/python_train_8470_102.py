import sys,os,io,time
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

def distinct(n):
    m=n
    dic={}
    while m>0:
        x=m%10
        m=m//10
        if x in dic:
            return False
        else:
            dic[x]=1
    return True

def main():
    n=int(input())
    i=n+1
    while True:
        if distinct(i):
            print(i)
            break
        i+=1

main()