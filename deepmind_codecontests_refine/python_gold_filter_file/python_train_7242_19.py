st = input()
B = st.count("B") # 1     
u = st.count("u") # 2
l = st.count("l") # 1
b = st.count("b") # 1
a = st.count("a") # 2
r = st.count("r") # 1
s = st.count("s") # 1

print(int(min(2*B,u,l*2,2*b,a,2*r,s*2)/2))
