; Auto-generated. Do not edit!


(cl:in-package server-srv)


;//! \htmlinclude addInt-request.msg.html

(cl:defclass <addInt-request> (roslisp-msg-protocol:ros-message)
  ((a
    :reader a
    :initarg :a
    :type cl:integer
    :initform 0)
   (b
    :reader b
    :initarg :b
    :type cl:integer
    :initform 0))
)

(cl:defclass addInt-request (<addInt-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <addInt-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'addInt-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name server-srv:<addInt-request> is deprecated: use server-srv:addInt-request instead.")))

(cl:ensure-generic-function 'a-val :lambda-list '(m))
(cl:defmethod a-val ((m <addInt-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server-srv:a-val is deprecated.  Use server-srv:a instead.")
  (a m))

(cl:ensure-generic-function 'b-val :lambda-list '(m))
(cl:defmethod b-val ((m <addInt-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server-srv:b-val is deprecated.  Use server-srv:b instead.")
  (b m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <addInt-request>) ostream)
  "Serializes a message object of type '<addInt-request>"
  (cl:let* ((signed (cl:slot-value msg 'a)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'b)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <addInt-request>) istream)
  "Deserializes a message object of type '<addInt-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'a) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'b) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<addInt-request>)))
  "Returns string type for a service object of type '<addInt-request>"
  "server/addIntRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'addInt-request)))
  "Returns string type for a service object of type 'addInt-request"
  "server/addIntRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<addInt-request>)))
  "Returns md5sum for a message object of type '<addInt-request>"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'addInt-request)))
  "Returns md5sum for a message object of type 'addInt-request"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<addInt-request>)))
  "Returns full string definition for message of type '<addInt-request>"
  (cl:format cl:nil "int32 a~%int32 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'addInt-request)))
  "Returns full string definition for message of type 'addInt-request"
  (cl:format cl:nil "int32 a~%int32 b~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <addInt-request>))
  (cl:+ 0
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <addInt-request>))
  "Converts a ROS message object to a list"
  (cl:list 'addInt-request
    (cl:cons ':a (a msg))
    (cl:cons ':b (b msg))
))
;//! \htmlinclude addInt-response.msg.html

(cl:defclass <addInt-response> (roslisp-msg-protocol:ros-message)
  ((sum
    :reader sum
    :initarg :sum
    :type cl:integer
    :initform 0))
)

(cl:defclass addInt-response (<addInt-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <addInt-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'addInt-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name server-srv:<addInt-response> is deprecated: use server-srv:addInt-response instead.")))

(cl:ensure-generic-function 'sum-val :lambda-list '(m))
(cl:defmethod sum-val ((m <addInt-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader server-srv:sum-val is deprecated.  Use server-srv:sum instead.")
  (sum m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <addInt-response>) ostream)
  "Serializes a message object of type '<addInt-response>"
  (cl:let* ((signed (cl:slot-value msg 'sum)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <addInt-response>) istream)
  "Deserializes a message object of type '<addInt-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'sum) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<addInt-response>)))
  "Returns string type for a service object of type '<addInt-response>"
  "server/addIntResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'addInt-response)))
  "Returns string type for a service object of type 'addInt-response"
  "server/addIntResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<addInt-response>)))
  "Returns md5sum for a message object of type '<addInt-response>"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'addInt-response)))
  "Returns md5sum for a message object of type 'addInt-response"
  "f0b6d69ea10b0cf210cb349d58d59e8f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<addInt-response>)))
  "Returns full string definition for message of type '<addInt-response>"
  (cl:format cl:nil "int32 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'addInt-response)))
  "Returns full string definition for message of type 'addInt-response"
  (cl:format cl:nil "int32 sum~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <addInt-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <addInt-response>))
  "Converts a ROS message object to a list"
  (cl:list 'addInt-response
    (cl:cons ':sum (sum msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'addInt)))
  'addInt-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'addInt)))
  'addInt-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'addInt)))
  "Returns string type for a service object of type '<addInt>"
  "server/addInt")