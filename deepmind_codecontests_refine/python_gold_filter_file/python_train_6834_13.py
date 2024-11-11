def func(k) :
    if k > 36 :
        return - 1
    ans = ""
    while k > 1 :
        ans += "8"
        k -= 2
    if k != 0 :
        ans += "6"
    return int(ans)

if __name__ == "__main__" :
    n = int(input())
    print(func(n))
