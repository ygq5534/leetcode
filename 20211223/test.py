#!/bin/python

import sys

S = "ADOBECODEBANC"
T = "ABC"

flag_a = 1;
dict_T = {}
for a in T:
    if a not in dict_T:
        dict_T[a] = flag_a
        flag_a += 1

list_s = []
for s in S:
    if s in dict_T:
        list_s.append(dict_T[s])
    else:
        list_s.append(0)


flags = [False for i in range(flag_a-1)]
list_pair = []
flag_end = False
for n in range(len(list_s)):
    if list_s[n]-1 >= 0 :
        l = n
        flags[list_s[l]-1] = True
        r = l+1
        while (False in flags): 
            if r >= len(list_s):
                flag_end = True
                break
            
            if list_s[r] - 1 < 0:
                r += 1
                continue

            flags[list_s[r]-1] = True
            r += 1
        flags = [False for i in range(flag_a-1)]
        if not flag_end:
            pair = (l,r)
            list_pair.append(pair)

min_pair = (0,len(list_s))
for nl,nr in list_pair:
    if nr-nl < min_pair[1]-min_pair[0]:
        min_pair = (nl,nr)

print (S[min_pair[0]:min_pair[1]])

#print ([nr-nl for nl,nr in list_pair])


