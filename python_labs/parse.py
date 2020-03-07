#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
from xml.dom.minidom import parse
import xml.dom.minidom
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
def getText(nodelist):
    for node in nodelist:
        if (node.nodeType != node.TEXT_NODE):
            print node.nodeName
            print node.nodeValue
    #        print node.attributes.item(0).value

def parse_tab(nodes, worksheet):
    if (nodes[0].hasChildNodes()):
        child_nodes = nodes[0].childNodes
        parse_tab(nodes, worksheet)
    print nodes[0].nodeName
    print nodes[0].nodeValue

def main():
    DOMTree = xml.dom.minidom.parse("movies.xml")
    collection = DOMTree.documentElement

    workbook = xlwt.Workbook(encoding = 'utf-8')
    worksheet = workbook.add_sheet('My Worksheet')

    sheet_name = "unsafe_func"
    sheet_items = collection.getElementsByTagName(sheet_name)
    print sheet_items
    print type(sheet_items)
    print "---------"
    tab_node = sheet_items[0]
    print tab_node
    print type(tab_node)
    print "---------"
    nodes = tab_node.childNodes
    print nodes
    print type(nodes)
    print "---------"
    sub_nodes = nodes[1]
    print sub_nodes
    print type(sub_nodes)
    print "---------"
    nodes = sub_nodes.childNodes
    print nodes
    print type(nodes)
    print "---------"
    #tab_node = parse_tab(nodes, worksheet)

if __name__ == "__main__":
    main()
