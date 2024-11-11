"""
Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
"""
from collections import Counter

if __name__ == "__main__":
    cases = int(input())

    for _ in range(cases):
        s = input()
        count = Counter(s)
        # print(count)

        c = []
        for v in count.values():
            if v > 2:
                c.append(2)
            else:
                c.append(v)

        colors = int(sum(c) / 2)
        print(colors)
