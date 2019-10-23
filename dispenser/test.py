import logging
import dispense
try:
  import config
except ImportError:
    print ("no config.py found.  Please copy sample_config.py to config.py.")


def test():
   dispense.dispense_init()
   dispense.dispense_back(config.servo_channel)
   time.sleep(2)
   dispense.dispense_forward(config.servo_channel)


def main(argv, stdout, environ):
  if sys.version_info < (3, 0): reload(sys); sys.setdefaultencoding('utf8')

  parser, args = parse_args(argv)

  numeric_loglevel = getattr(logging, args.log_level.upper(), None)
  if not isinstance(numeric_loglevel, int):
    raise ValueError('Invalid log level: %s' % args.log_level)

  logging.basicConfig(format="[%(asctime)s] %(levelname)-8s %(message)s",
                       datefmt="%m/%d %H:%M:%S", level=numeric_loglevel)


  test()

if __name__ == "__main__":
   main(sys.argv, sys.stdout, os.environ)

