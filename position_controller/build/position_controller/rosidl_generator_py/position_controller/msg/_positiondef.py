# generated from rosidl_generator_py/resource/_idl.py.em
# with input from position_controller:msg/Positiondef.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Positiondef(type):
    """Metaclass of message 'Positiondef'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('position_controller')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'position_controller.msg.Positiondef')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__positiondef
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__positiondef
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__positiondef
            cls._TYPE_SUPPORT = module.type_support_msg__msg__positiondef
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__positiondef

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Positiondef(metaclass=Metaclass_Positiondef):
    """Message class 'Positiondef'."""

    __slots__ = [
        '_posx',
        '_posy',
        '_postheta',
    ]

    _fields_and_field_types = {
        'posx': 'double',
        'posy': 'double',
        'postheta': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.posx = kwargs.get('posx', float())
        self.posy = kwargs.get('posy', float())
        self.postheta = kwargs.get('postheta', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.posx != other.posx:
            return False
        if self.posy != other.posy:
            return False
        if self.postheta != other.postheta:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def posx(self):
        """Message field 'posx'."""
        return self._posx

    @posx.setter
    def posx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posx' field must be of type 'float'"
        self._posx = value

    @property
    def posy(self):
        """Message field 'posy'."""
        return self._posy

    @posy.setter
    def posy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'posy' field must be of type 'float'"
        self._posy = value

    @property
    def postheta(self):
        """Message field 'postheta'."""
        return self._postheta

    @postheta.setter
    def postheta(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'postheta' field must be of type 'float'"
        self._postheta = value
