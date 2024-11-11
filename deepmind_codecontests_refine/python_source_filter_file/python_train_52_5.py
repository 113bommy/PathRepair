from collections import Counter
def main():
    a, n = ('+' + input()).replace(' ', '').replace('?', '').split('=')
    n = int(n)
    cnt = Counter(a)
    x, y = cnt['+'], cnt['-']
    if (n + y + x - 1) // x <= n and (n + y) // x > 0:
        print('Possible')
        d = (n + y + x - 1) // x
        c = n + x + y - d * x
        var = [str(d)] * c + [str(d - 1)] * (x - c)
        ans = []
        for _ in a:
            ans.append(_)
            if _ == '+':
                ans.append(var.pop())
            else:
                ans.append('1')
        ans.extend(['=', str(n)])
        print(' '.join(ans)[2:])
        return
    if y > 0 and x - n >= y and (x - n + y - 1) // y <= n:
        d = (x - n + y - 1) // y
        c = n + x + y - d * y
        var = [str(d)] * c + [str(d - 1)] * (y - c)
        ans = []
        for _ in a:
            ans.append(_)
            if _ == '+':
                ans.append('1')
            else:
                ans.append(var.pop())
        ans.extend(['=', str(n)])
        print('Possible')
        print(' '.join(ans)[2:])
        return
    print('Impossible')
main()
