def main():
    n,k = list(map(int, input().split()))
    a = list(map(int,input().split()))
    a.sort()
    sum = 0
    for i in a:
        if i < 5-k or i == 0:
            sum+= 1
    print(sum//3)
main()