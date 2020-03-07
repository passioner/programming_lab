#!/usr/bin/python
# -*- coding: UTF-8 -*-

import xml.etree.ElementTree as ET
import xlwt
 
#使用minidom解析器打开 XML 文档
#  DOMTree = xml.dom.minidom.parse("movies.xml")
#  collection = DOMTree.documentElement
#  if collection.hasAttribute("shelf"):
   #  print "Root element : %s" % collection.getAttribute("shelf")
 
#  movies = collection.getElementsByTagName("movie")
 
#  for movie in movies:
   #  print "*****Movie*****"
   #  if movie.hasAttribute("title"):
      #  print "Title: %s" % movie.getAttribute("title")
 
   #  type = movie.getElementsByTagName('type')[0]
   #  print "Type: %s" % type.childNodes[0].data
   #  format = movie.getElementsByTagName('format')[0]
   #  print "Format: %s" % format.childNodes[0].data
   #  rating = movie.getElementsByTagName('rating')[0]
   #  print "Rating: %s" % rating.childNodes[0].data
   #  description = movie.getElementsByTagName('description')[0]
   #  print "Description: %s" % description.childNodes[0].data

def parse_tab(tab_node, worksheet):
    while(tab_node.hasChildNodes()):
        tab_node = tab_node.childNodes[0]
    return tab_node

def main():
    DOMTree = ET.parse('movies.xml')
    root = DOMTree.getroot()

    workbook = xlwt.Workbook(encoding = 'utf-8')
    worksheet = workbook.add_sheet('My Worksheet')

    for unsafe_func in root.findall('unsafe_func'):
        fine_path = unsafe_func.get('name')
        line = unsafe_func.find('line').text
        func_name = unsafe_func.find('description').text
        print(fine_path, line, func_name)
if __name__ == "__main__":
    main()
