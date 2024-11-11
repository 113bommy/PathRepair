ans = {"1100000011": "A", "1000000010000000100000001": "B",
       "1111": "C", "1000000110000001": "D",
       "11000000011": "E", "100000001100000001": "F", "110000011": "G"}
while True:
    try:
        st = "".join([input() for _ in range(8)])

        st = st[st.find("1"): st.rfind("1")+1]
        for k, v in ans.items():
            if st == k:
                print(v)
                break
        input()
    except:
        break

