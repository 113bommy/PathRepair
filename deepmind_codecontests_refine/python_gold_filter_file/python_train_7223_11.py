for _ in range(int(input())):
    s = input()
    print(["OMG>.< I don't know!", "Freda's", "Rainbow's", "OMG>.< I don't know!"][s.startswith("miao.")
        * 2 + s.endswith("lala.")])
