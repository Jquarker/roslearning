
(cl:in-package :asdf)

(defsystem "server-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "addInt" :depends-on ("_package_addInt"))
    (:file "_package_addInt" :depends-on ("_package"))
  ))