d = {"a": input(), "b": input(), "c": input()}

def func(s):
    if len(d[s]) == 0:
        return s.upper()
    next = d[s][0]
    d[s] = d[s][1:]
    return func(next)

print(func(a))