import sys

a = [1,5,4,2,7,3]
a = [7,1,5,3,6,4]
res = 0
for i in range(1,len(a)):
    temp_a = a[i] - a[i-1]
    if temp_a > 0:
        res += temp_a
print (res)
