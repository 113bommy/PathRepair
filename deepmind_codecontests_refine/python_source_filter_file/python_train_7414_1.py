if __name__ == "__main__":
    for _ in range(int(input())):
        n, p, k = list(map(int, input().split()))
        a = list(map(int, input().split()))
        a.sort()
        pref = [0]
        for i in a[ : k - 1]:
            pref.append(pref[-1] + i)
        ans = 0
        for i, num in enumerate(pref):
            cur_ans = 0
            _p = p
            if _p >= num:
                _p -= num
                cur_ans += i
            else:
                break
            for j in range(i + k - 1, n, k):
                if _p >= a[j]:
                    cur_ans += k
                    _p -= a[j]
                else:
                    break
            ans = max(ans, cur_ans)
        print(">>", ans)
            