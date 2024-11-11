def check_left(i,n,a):
    ans = 0
    for i in range(i,n,-1):
        if a[i+1] >= a[i]:
            ans += 1
        else:
            break
    return ans

def check_right(i,n,a):
    ans = 0
    for i in range(i,n):
        if a[i] <= a[i-1]:
            ans += 1
        else:
            break

    return ans

def main():
    n = int(input())
    a = list(map(int,input().split()))
    ans = -1
    for i in range(n):
        temp = 1
        temp += check_left(i-1,0,a)
        temp += check_right(i+1,n,a)
        ans = max(temp,ans)
    print(ans)


if __name__ == '__main__':
    main()
