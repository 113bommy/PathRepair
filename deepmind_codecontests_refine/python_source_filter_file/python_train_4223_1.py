d, k, a, b, t = map(int, input().split())

def main():
    if d <= k:
        print("case 0")
        return d*a
    else:
        ans = a*k
        p = k
        if (b*k <= t + k*a):
            print("case 1")
            ans += (d - k)*b
        else:
            print("case 2")
            pp = (d - k)//k
            p += pp*k
            ans += pp*(t + k*a)
            if (d-p)*b < t + (d-p)*a:
                ans += (d-p)*b
            else:
                ans += t + (d-p)*a
        return ans

print(main())
