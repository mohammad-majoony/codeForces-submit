a , b , s = list(map(int,input().split()))
count = abs(a) + abs(b)
if count > s : print("NO")
elif (count - s) % 2 == 0 : print("YES")
else : print("NO")