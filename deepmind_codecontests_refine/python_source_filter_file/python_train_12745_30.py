def solve(n, c, off):
    ans = '({})'.format(c)

    # go right
    tem_off = off
    counter = c+1
    while tem_off and counter <= n:
        ans += ' {}'.format(counter)
        counter += 1
        tem_off -= 1
    if n-c > off:
        ans += ' >>'
    
    # go left
    tem_off = off
    counter = c-1
    while tem_off and counter >= 1:
        ans = '{} '.format(counter) + ans
        counter -= 1
        tem_off -= 1

    if c-1 > off: ans = '<< ' + ans
    return ans.strip()

if __name__ == '__main__':
    n,k,off = map(int,input().split(" "))
    solve(n,k,off)