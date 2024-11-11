n, m = map(int, input().split())

out = []

for i in range(1, n + 1):
    if i % 2:
        out.append("".join(["#"] * m))
    elif not i % 4:
        out.append("".join(["."] * (m - 1) + ["#"]))
    else:
        out.append("".join(["#"] + ["."] * (m - 1)))

for line in out:
    print(line)
