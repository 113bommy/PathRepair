s = input()
if len(s) == 0:
    print(0)
else:
    n_b, i_b, e_b, t_b = 2, 1, 3, 1
    f = lambda s: [s.count(x) for x in ["n", "i", "e", "t"]]
    count = lambda n, i, e, t: min((n - 1) // n_b, i // i_b, e // e_b, t // t_b)
    print(count(*f(s)))