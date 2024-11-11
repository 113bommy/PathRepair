USE_STDIO = False

if not USE_STDIO:
    try: import mypc
    except: pass

def main():
    n, h, a, b, k = map(int, input().split(' '))
    for _ in range(k):
        ta, fa, tb, fb = map(int, input().split(' '))
        if ta == tb:
            ans = abs(fa - fb)
        else:
            ans = abs(ta - tb)
            if fa > fb: fa, fb = fb, fa
            if a <= fa <= b or fa <= a <= fb:
                ans += fb - fa
            elif fa >= b:
                ans += fa - b + fb - b
            elif fb <= a:
                ans += fa - a + fb - a
        print(ans)


if __name__ == '__main__':
    main()



