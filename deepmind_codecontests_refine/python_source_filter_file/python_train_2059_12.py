a,v,b,w,t=map(int,open(0).read().split())
print(['NO','YES'][w<v and b-a<=(v-w)*t])