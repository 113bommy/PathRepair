perfects = []
for a in range(1, 10):
    perfects.append("{}{}".format(a, 10 - a))
    for b in range(10 - a):
        if (a + b) <= 10:
            perfects.append("{}{}{}".format(a, b, 10 - a - b))
        for c in range(10 - a - b):
            if (a + b + c) <= 10:
                perfects.append("{}{}{}{}".format(a, b, c, 10 - a - b - c))
            for d in range(10 - a - b - c):
                if (a + b + c + d) <= 10:
                    perfects.append("{}{}{}{}{}".format(a, b, c, d, 10 - a - b - c - d))
                for e in range(10 - a - b - c - d):
                    if (a + b + c + d + e) <= 10:
                        perfects.append("{}{}{}{}{}{}".format(a, b, c, d, e, 10 - a - b - c - d - e))
                    for f in range(10 - a - b - c - d - e):
                        if (a + b + c + d + e + f) <= 10:
                            perfects.append("{}{}{}{}{}{}{}".format(a, b, c, d, e, f, 10 - a - b - c - d - e - f))
                        for g in range(10 - a - b - c - d - e - f):
                            if (a + b + c + d + e + f + g) <= 10:
                                perfects.append("{}{}{}{}{}{}{}{}".format(a, b, c, d, e, f, g, 10 - a - b - c - d - e - f - g))
perfects = sorted([int(x) for x in perfects])
print(perfects[int(input()) - 1])