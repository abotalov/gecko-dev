# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

from marionette_test import MarionetteTestCase

class TestValueOfCssProperty(MarionetteTestCase):
    def test_getAttribute(self):
        test_html = self.marionette.absolute_url("element_bottom.html")
        self.marionette.navigate(test_html)
        el = self.marionette.find_element("css selector", ".element")
        self.assertEqual("absolute", el.value_of_css_property("position"))

    def test_that_color_value_is_returned_in_rgba_format(self):
        test_html = self.marionette.absolute_url("element_bottom.html")
        self.marionette.navigate(test_html)
        el = self.marionette.find_element("css selector", ".element")
        self.assertEqual('rgba(255, 0, 0, 1)', el.value_of_css_property("background-color"))
