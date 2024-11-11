s, t = [input() for _ in range(2)]
jprint('Yes' if sorted(s) < sorted(t, reverse=True) else 'No')