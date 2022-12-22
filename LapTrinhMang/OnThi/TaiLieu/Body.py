# -*- coding: utf-8 -*-
"""
Created on Sat Jun  4 11:25:16 2022

@author: dangq
"""

import urllib
from urllib.request import urlopen
import re
htmlfile =urlopen('http://www.vnexpress.net')
htmltext = htmlfile.read()
regex = '<body>(.+?)</body>'
pattern = re.compile(regex)
title = re.findall(pattern, htmltext)
print(title)