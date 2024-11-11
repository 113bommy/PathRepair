GI = lambda: int(input()); GIS = lambda: map(int, input().split()); LGIS = lambda: list(GIS())

from collections import Counter

def main():
    for _ in range(GI()):
        n, k = GIS()
        xs = LGIS()
        ctr = Counter(xs)
        nums_to_colors = {}
        cc = 0
        for x, c in ctr.most_common():
            colors = nums_to_colors.setdefault(x, [])
            for i in range(min(c, k)):
                colors.append(cc + 1)
                cc = (cc + 1) % k

        if cc:
            for num, colors in nums_to_colors.items():
                while colors and colors[-1] == cc:
                    colors.pop()
                    cc -= 1
                    if not cc:
                        break
                if not cc:
                    break

        colors = [0] * n
        for i, x in enumerate(xs):
            colors[i] = nums_to_colors[x].pop() if nums_to_colors[x] else 0

        print(' '.join(map(str, colors)))

main()
