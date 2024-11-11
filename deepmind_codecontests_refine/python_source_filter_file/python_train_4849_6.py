import re


def foo():
    n = int(input())
    who = input().split()
    m = int(input())
    msg = []

    l = []

    for num in range(m):
        a, t = input().split(':')
        msg.append(t)

        st = set()

        if a != '?':
            st.add(a)
        else:

            names = re.split('\W+', t)

            for w in who:
                if not w in names:
                    st.add(w)

        l.append(st)

    d2 = []

    for num in range(1, m):
        d = {}
        for w1 in l[num]:
            for w2 in l[num - 1]:
                if w1 != w2:
                    d[w1] = w2
                    break

        l[num] = [x for x in d]

        d2.append(d)

    curr = None

    for w in l[num - 1]:
        curr = w

    res = [curr]

    for num in list(reversed(range(1, m))):
        curr = d2[num - 1].get(curr, None)  # d2[num - 1][curr]
        res.append(curr)

    res = list(reversed(res))

    if None in res:
        print("Impossible")
    else:
        for num in range(m):
            print(res[num] + ':' + msg[num])


t = int(input())

for _ in range(t):
    foo()
