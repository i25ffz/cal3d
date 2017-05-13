import sys
import struct
from PyQt4 import QtGui

class ImageLabel(QtGui.QLabel):
	def __init__(self, parent=None):
		QtGui.QLabel.__init__(self, parent)

		self.setWindowTitle('Window')

	def loadImg(self, img):
		f = open(img, "rb")

		w = struct.unpack("i", f.read(struct.calcsize("i")))[0]
		h = struct.unpack("i", f.read(struct.calcsize("i")))[0]
		d = struct.unpack("i", f.read(struct.calcsize("i")))[0]
		self.setGeometry(300, 300, w, h)

		print 'w:', w
		print 'h:', h
		print 'd:', d
		if d == 4:
			qimage = QtGui.QImage(f.read(w * h * d), w, h, QtGui.QImage.Format_ARGB32)
		else:
			qimage = QtGui.QImage(f.read(w * h * d), w, h, QtGui.QImage.Format_RGB888)
		self.pix = QtGui.QPixmap.fromImage(qimage)
		self.setPixmap(self.pix)

app = QtGui.QApplication(sys.argv)
imageLabel = ImageLabel()
imageLabel.loadImg(sys.argv[1])
imageLabel.show()
sys.exit(app.exec_())
