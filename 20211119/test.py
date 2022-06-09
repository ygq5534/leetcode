#!/bin/pyhon

#import sys 
#
#a = "ababcbacadefegdehijhklij"
#list_res = []
#begin = 0
#end = 0
#for i in range(len(a)):
#    if i <= end:
#        continue
#    a1 = a[i+1:]
#    r = a1.find(a[i])
#    if r == -1:
#        begin = end 
#        end = i
#        print (begin)
#        print (end)
#        list_res.append(a[begin:end])
#print (list_res)

import sys

a = "ababcbacadefegdehijhklij"
dict_a = {}
for i in range(len(a)):
    dict_a[a[i]] = i
list_res = []
list_res1 = []
begin = 0
end = 0
for i in range(len(a)):
    end = max(int(dict_a[a[i]]),int(end))
    if i == end:
        list_res.append(a[begin:end+1])
        begin = i + 1;
print (list_res)
