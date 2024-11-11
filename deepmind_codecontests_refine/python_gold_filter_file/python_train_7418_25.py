def main():
    test=int(input())
    for _ in range(test):
        t=int(input())
        ans=t-30
        if ans<=0:
            print('NO')
        else:
            print('YES')
            if t==36 or t==40 or t==44:
                print(6,10,15,ans-1)
            else:
                print(6,10,14,ans)
main()