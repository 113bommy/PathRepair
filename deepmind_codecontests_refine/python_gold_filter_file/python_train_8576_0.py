n = input()
if int(n) >= 0:
    print(n)
else:
    n = f"0{n[1:]}"
    if f"-{min(int(n[:-1]), int(f'{n[:-2]}{n[-1]}'))}" == "-0":
        print(0)
    else:
        print(f"-{min(int(n[:-1]), int(f'{n[:-2]}{n[-1]}'))}")
