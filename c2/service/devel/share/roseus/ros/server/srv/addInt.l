;; Auto-generated. Do not edit!


(when (boundp 'server::addInt)
  (if (not (find-package "SERVER"))
    (make-package "SERVER"))
  (shadow 'addInt (find-package "SERVER")))
(unless (find-package "SERVER::ADDINT")
  (make-package "SERVER::ADDINT"))
(unless (find-package "SERVER::ADDINTREQUEST")
  (make-package "SERVER::ADDINTREQUEST"))
(unless (find-package "SERVER::ADDINTRESPONSE")
  (make-package "SERVER::ADDINTRESPONSE"))

(in-package "ROS")





(defclass server::addIntRequest
  :super ros::object
  :slots (_a _b ))

(defmethod server::addIntRequest
  (:init
   (&key
    ((:a __a) 0)
    ((:b __b) 0)
    )
   (send-super :init)
   (setq _a (round __a))
   (setq _b (round __b))
   self)
  (:a
   (&optional __a)
   (if __a (setq _a __a)) _a)
  (:b
   (&optional __b)
   (if __b (setq _b __b)) _b)
  (:serialization-length
   ()
   (+
    ;; int32 _a
    4
    ;; int32 _b
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _a
       (write-long _a s)
     ;; int32 _b
       (write-long _b s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _a
     (setq _a (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _b
     (setq _b (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass server::addIntResponse
  :super ros::object
  :slots (_sum ))

(defmethod server::addIntResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass server::addInt
  :super ros::object
  :slots ())

(setf (get server::addInt :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get server::addInt :datatype-) "server/addInt")
(setf (get server::addInt :request) server::addIntRequest)
(setf (get server::addInt :response) server::addIntResponse)

(defmethod server::addIntRequest
  (:response () (instance server::addIntResponse :init)))

(setf (get server::addIntRequest :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get server::addIntRequest :datatype-) "server/addIntRequest")
(setf (get server::addIntRequest :definition-)
      "int32 a
int32 b
---
int32 sum

")

(setf (get server::addIntResponse :md5sum-) "f0b6d69ea10b0cf210cb349d58d59e8f")
(setf (get server::addIntResponse :datatype-) "server/addIntResponse")
(setf (get server::addIntResponse :definition-)
      "int32 a
int32 b
---
int32 sum

")



(provide :server/addInt "f0b6d69ea10b0cf210cb349d58d59e8f")


